/**
 * @file main.js
 * @brief main js 
 *
 * Check if the browser supports The Web Serial API, and display port list
 * 
 * @version 1.0.0
 * 
 * @author Walid Amriou
 * @date 07/26/2021
 * 
 * Tachimetro project
 *  
 */

class LineBreakTransformer {
  constructor() {
    this.container = '';
  }
  transform(chunk, controller) {
    this.container += chunk;
    const lines = this.container.split('i');
    this.container = lines.pop();
    lines.forEach(line => controller.enqueue(line));
  }
  flush(controller) {
    controller.enqueue(this.container);
  }
}
// Check if the browser support The Web Serial API  
async function start() {
  let datasend = "";
  let h1 = document.getElementsByTagName('h1')[0];
  if ('serial' in navigator) {
    console.log('Your browser support the Web Serial API.');
    const port = await navigator.serial.requestPort();
    await port.open({
      baudRate: 9600
    });
    const writer = port.writable.getWriter();
    //const reader = port.readable.getReader();  
    while (port.readable) {
      const textDecoder = new TextDecoderStream();
      const readableStreamClosed = port.readable.pipeTo(textDecoder.writable);
      //const reader = textDecoder.readable.getReader();
      const reader = textDecoder.readable.pipeThrough(new TransformStream()).getReader();
      try {
        while (true) {
          const {
            value,
            done
          } = await reader.read();
          if (done) {
            // Allow the serial port to be closed later.
            reader.releaseLock();
            break;
          }
          //if (value) {
          //console.log(value); // for test
          //}
          let arrValue = [...value];
          //console.log(arrValue);
          let arraylength = arrValue.length;
          for (let i = 0; i < arraylength; i++) {
            //const trimmedValue = arrValue[i].replace(/(?:\r\n|\r|\n)/g, '').trim();
            if (arrValue[i] != ",") {
              datasend += arrValue[i]; // save to buffer
              //console.log(arrValue[i]);
            } else if (arrValue[i] === ",") {
              console.log(datasend);
              datasend = datasend / 1000000; // us to s
              datasend = 1 / datasend; // T to F
              datasend = datasend * 10; // RPM = F * 60 / 6 poles
              datasend = Math.floor(datasend); // remove after dot
              h1.innerHTML = datasend; // print value
              datasend = ""; // clear buffer
            }
          }
        }
      } catch (error) {
        // TODO: Handle non-fatal read error.
        console.error(error);
      }
    }
  } else {
    console.log('The Web serial API doesn\'t enabled in your browser or not supported.');
  }
}