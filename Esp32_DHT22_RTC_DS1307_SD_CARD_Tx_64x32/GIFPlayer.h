/*
 * Adapted by 3tawi
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef GIFPlayer_H
#define GIFPlayer_H

#include <AnimatedGIF.h>
AnimatedGIF gif;


void * GIFOpenFile(const char *fname, int32_t *pSize)
{
  //Serial.print("Playing gif: ");
  //Serial.println(fname);
  f = SD.open(fname);
  if (f)
  {
    *pSize = f.size();
    return (void *)&f;
  }
  return NULL;
} /* GIFOpenFile() */

void GIFCloseFile(void *pHandle)
{
  File *f = static_cast<File *>(pHandle);
  if (f != NULL)
     f->close();
} /* GIFCloseFile() */

int32_t GIFReadFile(GIFFILE *pFile, uint8_t *pBuf, int32_t iLen)
{
    int32_t iBytesRead;
    iBytesRead = iLen;
    File *f = static_cast<File *>(pFile->fHandle);
    // Note: If you read a file all the way to the last byte, seek() stops working
    if ((pFile->iSize - pFile->iPos) < iLen)
       iBytesRead = pFile->iSize - pFile->iPos - 1; // <-- ugly work-around
    if (iBytesRead <= 0)
       return 0;
    iBytesRead = (int32_t)f->read(pBuf, iBytesRead);
    pFile->iPos = f->position();
    return iBytesRead;
} /* GIFReadFile() */

int32_t GIFSeekFile(GIFFILE *pFile, int32_t iPosition)
{ 
  int i = micros();
  File *f = static_cast<File *>(pFile->fHandle);
  f->seek(iPosition);
  pFile->iPos = (int32_t)f->position();
  i = micros() - i;
//  Serial.printf("Seek time = %d us\n", i);
  return pFile->iPos;
} /* GIFSeekFile() */

void GIFDraw(GIFDRAW *pDraw) {
  int y = (pDraw->iY + pDraw->y), xy; 
  if (pDraw->y ==0){
    memset(buff, 0xFF, NUM_LEDS);
    memcpy(usPalette, (uint8_t *)pDraw->pPalette, 510);
  }
  if (y < kMatrixHeight) {
    xy = (kMatrixWidth * y) + pDraw->iX;
    uint8_t iWidth = (pDraw->iWidth < kMatrixWidth) ? pDraw->iWidth : kMatrixWidth;
    memcpy((buff+xy), (uint8_t *)pDraw->pPixels, iWidth);
  }
} /* GIFDraw() */

void GIFDraw8(GIFDRAW *pDraw) {
  uint8_t *s = pDraw->pPixels, c;
  int y = (pDraw->iY + pDraw->y), xy; 
  if (pDraw->y ==0){
    memcpy(usPalettec, (uint8_t *)pDraw->pPalette, 510);
  }
  xy = (kMatrixWidth * y) + pDraw->iX;
  for (int i=0; i<pDraw->iWidth; i++) {
    c = *s++;
    if (c != 0xFF)
      buffc[i+xy] = (rgb8)usPalettec[c];
  }
} /* GIFDraw() */

void ShowGIF(char *name)
{
  if (gif.open(name, GIFOpenFile, GIFCloseFile, GIFReadFile, GIFSeekFile, GIFDraw)) {
    while (gif.playFrame(true, NULL))
    { 
      server.handleClient();
      mySeriel->write(UpHeader);
      mySeriel->write((uint8_t *)usPalette, 510);
      mySeriel->write((uint8_t *)buff, NUM_LEDS);
      mySeriel->write(endHeader); 
      if(ModeAuto) {
        if (millis() - prevTime > sp3*1000) {
          start_tick = true;
          prevTime = millis();
        }
      }  
      if (start_tick)
        break;
    }
    start_tick = false;
    gif.close();
  }
} /* ShowGIF() */

#endif
