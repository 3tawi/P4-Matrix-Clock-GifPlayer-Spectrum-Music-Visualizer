/*
 * Adapted by 3tawi
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * http://www.stefan-petrick.de/wordpress_beta
 * Copyright (c) 2014 Stefan Petrick
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef AudioP_H
#define AudioP_H

class AudioP : public Playlist {
  private:
  const int CENTRE_X = 32;
  const int CENTRE_Y = 16;
  
  public:
    typedef void (AudioP::*AudioPFunctionPointer)(void);
    AudioPFunctionPointer curtItem;
    static const int P_COUNT = 77;
    AudioPFunctionPointer shufItems[P_COUNT];
    AudioPFunctionPointer itemP[P_COUNT] = {
      &AudioP::SpMuAudio1,
      &AudioP::SpMuAudio2,
      &AudioP::SpMuAudio3,
      &AudioP::SpMuAudio4,
      &AudioP::SpMuAudio5,
      &AudioP::SpMuAudio6,
      &AudioP::SpMuAudio7,
      &AudioP::SpMuAudio8,
      &AudioP::SpMuAudio9,
      &AudioP::SpMuAudio10,
      &AudioP::SpMuAudio11,
      &AudioP::SpMuAudio12,
      &AudioP::SpMuAudio13,
      &AudioP::SpMuAudio14,
      &AudioP::SpMuAudio15,
      &AudioP::SpMuAudio16,
      &AudioP::SpMuAudio17,
      &AudioP::SpMuAudio18,
      &AudioP::SpMuAudio19,
      &AudioP::SpMuAudio20,
      &AudioP::SpMuAudio21,
      &AudioP::SpMuAudio22,
      &AudioP::SpMuAudio23,
      &AudioP::SpMuAudio24,
      &AudioP::SpMuAudio25,
      &AudioP::SpMuAudio26,
      &AudioP::SpMuAudio27,
      &AudioP::SpMuAudio28,
      &AudioP::SpMuAudio29,
      &AudioP::SpMuAudio30,
      &AudioP::SpMuAudio31,
      &AudioP::SpMuAudio32,
      &AudioP::SpMuAudio33,
      &AudioP::SpMuAudio34,
      &AudioP::SpMuAudio35,
      &AudioP::SpMuAudio36,
      &AudioP::SpMuAudio37,
      &AudioP::SpMuAudio38,
      &AudioP::SpMuAudio39,
      &AudioP::SpMuAudio40,
      &AudioP::SpMuAudio41,
      &AudioP::SpMuAudio42,
      &AudioP::SpMuAudio43,
      &AudioP::SpMuAudio44,
      &AudioP::SpMuAudio45,
      &AudioP::SpMuAudio46,
      &AudioP::SpMuAudio47,
      &AudioP::SpMuAudio48,
      &AudioP::SpMuAudio49,
      &AudioP::SpMuAudio50,
      &AudioP::SpMuAudio51,
      &AudioP::SpMuAudio52,
      &AudioP::SpMuAudio53,
      &AudioP::SpMuAudio54,
      &AudioP::SpMuAudio55,
      &AudioP::SpMuAudio56,
      &AudioP::SpMuAudio57,
      &AudioP::SpMuAudio58,
      &AudioP::SpMuAudio59,
      &AudioP::SpMuAudio60,
      &AudioP::SpMuAudio61,
      &AudioP::SpMuAudio62,
      &AudioP::SpMuAudio63,
      &AudioP::SpMuAudio64,
      &AudioP::SpMuAudio65,
      &AudioP::SpMuAudio66,
      &AudioP::SpMuAudio67,
      &AudioP::SpMuAudio68,
      &AudioP::SpMuAudio69,
      &AudioP::SpMuAudio70,
      &AudioP::SpMuAudio71,
      &AudioP::SpMuAudio72,
      &AudioP::SpMuAudio73,
      &AudioP::SpMuAudio74,
      &AudioP::SpMuAudio75,
      &AudioP::SpMuAudio76,
      &AudioP::SpMuAudio77
    };
    
    void SpMuAudio1() {
      drawAudio1(0);
    }
    void SpMuAudio2() {
      drawAudio1(1);
    }
    void SpMuAudio3() {
      drawAudio1(2);
    }
    void SpMuAudio4() {
      drawAudio1(3);
    }
    void SpMuAudio5() {
      drawAudio1(4);
    }
    void SpMuAudio6() {
      drawAudio1(5);
    }
    void SpMuAudio7() {
      drawAudio1(6);
    }
    void SpMuAudio8() {
      drawAudio1(7);
    }
    void SpMuAudio9() {
      drawAudio1(8);
    }
    void SpMuAudio10() {
      drawAudio1(9);
    }
    void SpMuAudio11() {
      drawAudio1(10);
    }
    void SpMuAudio12() {
      drawAudio1(11);
    }
    void SpMuAudio13() {
      drawAudio1(12);
    }
    void SpMuAudio14() {
      drawAudio1(13);
    }
    void SpMuAudio15() {
      drawAudio1(14);
    }
    void SpMuAudio16() {
      drawAudio2(0);
    }
    void SpMuAudio17() {
      drawAudio2(1);
    }
    void SpMuAudio18() {
      drawAudio2(2);
    }
    void SpMuAudio19() {
      drawAudio2(3);
    }
    void SpMuAudio20() {
      drawAudio2(4);
    }
    void SpMuAudio21() {
      drawAudio2(5);
    }
    void SpMuAudio22() {
      drawAudio2(6);
    }
    void SpMuAudio23() {
      drawAudio2(7);
    }
    void SpMuAudio24() {
      drawAudio2(8);
    }
    void SpMuAudio25() {
      drawAudio2(9);
    }
    void SpMuAudio26() {
      drawAudio2(10);
    }
    void SpMuAudio27() {
      drawAudio2(11);
    }
    void SpMuAudio28() {
      drawAudio2(12);
    }
    void SpMuAudio29() {
      drawAudio2(13);
    }
    void SpMuAudio30() {
      drawAudio3(0);
    }
    void SpMuAudio31() {
      drawAudio3(1);
    }
    void SpMuAudio32() {
      drawAudio3(2);
    }
    void SpMuAudio33() {
      drawAudio3(3);
    }
    void SpMuAudio34() {
      drawAudio3(4);
    }
    void SpMuAudio35() {
      drawAudio3(5);
    }
    void SpMuAudio36() {
      drawAudio3(6);
    }
    void SpMuAudio37() {
      drawAudio3(7);
    }
    void SpMuAudio38() {
      drawAudio3(8);
    }
    void SpMuAudio39() {
      drawAudio3(9);
    }
    void SpMuAudio40() {
      drawAudio3(10);
    }
    void SpMuAudio41() {
      drawAudio3(11);
    }
    void SpMuAudio42() {
      drawAudio3(12);
    }
    void SpMuAudio43() {
      drawAudio4(0);
    }
    void SpMuAudio44() {
      drawAudio4(1);
    }
    void SpMuAudio45() {
      drawAudio4(2);
    }
    void SpMuAudio46() {
      drawAudio4(3);
    }
    void SpMuAudio47() {
      drawAudio4(4);
    }
    void SpMuAudio48() {
      drawAudio4(5);
    }
    void SpMuAudio49() {
      drawAudio4(6);
    }
    void SpMuAudio50() {
      drawAudio4(7);
    }
    void SpMuAudio51() {
      drawAudio4(8);
    }
    void SpMuAudio52() {
      drawAudio4(9);
    }
    void SpMuAudio53() {
      drawAudio4(10);
    }
    void SpMuAudio54() {
      drawAudio5(0);
    }
    void SpMuAudio55() {
      drawAudio5(1);
    }
    void SpMuAudio56() {
      drawAudio5(2);
    }
    void SpMuAudio57() {
      drawAudio5(3);
    }
    void SpMuAudio58() {
      drawAudio5(4);
    }
    void SpMuAudio59() {
      drawAudio5(5);
    }
    void SpMuAudio60() {
      drawAudio5(6);
    }
    void SpMuAudio61() {
      drawAudio5(7);
    }
    void SpMuAudio62() {
      drawAudio5(8);
    }
    void SpMuAudio63() {
      drawAudio5(9);
    }
    void SpMuAudio64() {
      drawAudio5(10);
    }
    void SpMuAudio65() {
      drawAudio6(0);
    }
    void SpMuAudio66() {
      drawAudio6(1);
    }
    void SpMuAudio67() {
      drawAudio6(2);
    }
    void SpMuAudio68() {
      drawAudio6(3);
    }
    void SpMuAudio69() {
      drawAudio6(4);
    }
    void SpMuAudio70() {
      drawAudio6(5);
    }
    void SpMuAudio71() {
      drawAudio6(6);
    }
    void SpMuAudio72() {
      drawAudio6(7);
    }
    void SpMuAudio73() {
      drawAudio6(8);
    }
    void SpMuAudio74() {
      drawAudio6(9);
    }
    void SpMuAudio75() {
      drawAudio6(10);
    }
    void SpMuAudio76() {
      drawAudio6(11);
    }
    void SpMuAudio77() {
      drawAudio6(12);
    }

    void drawMode1(int x1, int x2, int y1, int y2, uint8_t color, uint8_t color0, int md) {
      switch(md) {
        case 0 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, 31, x1, y1, x2, y2, color0);
        break;
        case 1 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        break;
        case 2 :
        effects.fillTriangle(x1, y1, x2, y2, x1, y2, color);
        effects.fillTriangle(x1, y1, x2, y2, x2, y1, color);
        break;
        case 3 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        break;
        case 4 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color0);
        break;
        case 5 :
        effects.fillTriangle(x1, y1, x2, y2, x1, y2, color);
        break;
        case 6 :
        effects.fillTriangle(x1, y1, x2, y2, x2, y1, color);
        break;
        case 7 :
        effects.drawLine(x1, y1, x2, y1, color);
        effects.drawLine(x1, y1, x1, y2, color0);
        effects.drawLine(x2, y2, x1, y2, color);
        effects.drawLine(x2, y2, x2, y1, color0);
        break;
        case 8 :
        effects.drawLine(x1, y1, x2, y2, color);
        break;
        case 9 :
        effects.drawLine(x1, y1, x1, y2, color);
        effects.drawLine(x2, y2, x1, y2, color0);
        break;
        case 10 :
        effects.fillTriangle(x1, y1, x1, y2, x2, y1, color);
        effects.fillTriangle(x2, y2, x2, y1, x1, y2, color0);
        break;
        case 11 :
        effects.fillTriangle(x1, y1, x1, 31, x2, 31, color);
        effects.fillTriangle(x2, y2, x2, 31, x1, 31, color);
        break;
        case 12 :
        effects.fillTriangle(x1, y1, x2, y2, x1, 31, color);
        effects.fillTriangle(x1, y1, x2, y2, x2, 31, color);
        break;
        case 13 :
        effects.fillRect(x1, y1, x2-x1, 31-((y1+y2)/2), color);
        break;
        case 14 :
        int w = (x2-x1)/2;
        effects.fillRect(x1, y1, w, 31-y1, color);
        effects.fillRect(x1+w, y2, w, 31-y2, color0);
        break;
      }
    }
    
    void drawMode2(int x1, int x2, int x3, int y1, int y2, int y3, uint8_t color, uint8_t color0, int md) {
      switch(md) {
        case 0 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color0);
        break;
        case 1 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x2, y2, x3, y3, color);
        effects.drawTriangle(CENTRE_X, CENTRE_Y, x2, y2, x3, y3, color0);
        break;
        case 4 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x3, y3, color0);
        break;
        case 2 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        break;
        case 3 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x3, y3, color);
        break;
        case 5 :
        effects.fillTriangle(x2, y1, x2, y2, x2, y3, color);
        effects.fillTriangle(x3, y1, x3, y2, x3, y3, color0);
        break;
        case 6 :
        effects.fillTriangle(x1, y1, x2, y2, x3, y3, color);
        effects.fillTriangle(x1, y1, x1, y2, x3, y3, color0);
        effects.fillTriangle(63-x1, 31-y1, 63-x2, 31-y2, 63-x3, 31-y3, color);
        effects.fillTriangle(63-x1, 31-y1, 63-x1, 31-y2, 63-x3, 31-y3, color0);
        break;
        case 7 :
        effects.fillTriangle(x1, y1, x2, y2, x3, y3, color);
        effects.fillTriangle(x1, y1, x1, y2, x3, y3, color0);
        effects.fillTriangle(63-x1, 31-y1, 63-x2, 31-y2, 63-x3, 31-y3, color);
        effects.fillTriangle(63-x1, 31-y1, 63-x1, 31-y2, 63-x3, 31-y3, color0);
        break;
        case 8 :
        effects.fillTriangle(x2, y1, x2, y2, x2, y3, color);
        effects.fillTriangle(x3, y1, x3, y2, x3, y3, color0);
        effects.fillTriangle(63-x2, 31-y1, 63-x2, 31-y2, 63-x2, 31-y3, color);
        effects.fillTriangle(63-x3, 31-y1, 63-x3, 31-y2, 63-x3, 31-y3, color0);
        break;
        case 9 :
        effects.fillTriangle(x3, y1, x3, y2, x1, y3, color);
        effects.drawTriangle(x3, y1, x3, y2, x1, y3, color0);
        effects.fillTriangle(63-x3, 31-y1, 63-x3, 31-y2, 63-x1, 31-y3, color);
        effects.drawTriangle(63-x3, 31-y1, 63-x3, 31-y2, 63-x1, 31-y3, color0);
        break;
        case 10 :
        effects.fillTriangle(x2, y1, x3, y1, x2, y3, color);
        effects.drawTriangle(x2, y1, x3, y1, x2, y3, color0);
        effects.fillTriangle(63-x2, 31-y1, 63-x3, 31-y1, 63-x2, 31-y3, color);
        effects.drawTriangle(63-x2, 31-y1, 63-x3, 31-y1, 63-x2, 31-y3, color0);
        break;
        case 11 :
        effects.drawLine(x1, y1, x2, y2, color);
        effects.drawLine(x1, y1, x3, y3, color0);
        break;
        case 12 :
        effects.drawLine(x1, y1, x2, y2, color);
        effects.drawLine(x2, y2, x3, y3, color0);
        effects.drawLine(63-x1, 31-y1, 63-x2, 31-y2, color);
        effects.drawLine(63-x2, 31-y2, 63-x3, 31-y3, color0);
        break;
        case 13 :
        effects.drawLine(x1, y1, x1, y2, color);
        effects.drawLine(x1, y2, x2, y2, color0);
        effects.drawLine(x1, y1, x3, y1, color);
        effects.drawLine(x3, y1, x3, y3, color0);
        effects.drawLine(63-x1, 31-y1, 63-x1, 31-y2, color0);
        effects.drawLine(63-x1, 31-y2, 63-x2, 31-y2, color);
        effects.drawLine(63-x1, 31-y1, 63-x3, 31-y1, color0);
        effects.drawLine(63-x3, 31-y1, 63-x3, 31-y3, color);
        break;
      }
    }
    
    void drawMode3(int x1, int x2, int y1, int y2, uint8_t color, uint8_t color0, int md) {
      switch(md) {
        case 0 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, 31, x1, y1, x2, y2, color0);
        break;
        case 1 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        break;
        case 2 :
        effects.fillTriangle(x1, y1, x2, y2, x1, y2, color);
        effects.fillTriangle(x1, y1, x2, y2, x2, y1, color);
        break;
        case 3 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        break;
        case 4 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color0);
        break;
        case 5 :
        effects.fillTriangle(x1, y1, x2, y2, x1, y2, color);
        break;
        case 6 :
        effects.fillTriangle(x1, y1, x2, y2, x2, y1, color);
        break;
        case 7 :
        effects.drawLine(x1, y1, x2, y1, color);
        effects.drawLine(x1, y1, x1, y2, color0);
        effects.drawLine(x2, y2, x1, y2, color);
        effects.drawLine(x2, y2, x2, y1, color0);
        break;
        case 8 :
        effects.drawLine(x1, y1, x2, y2, color);
        break;
        case 9 :
        effects.drawLine(x1, y1, x1, y2, color);
        effects.drawLine(x2, y2, x1, y2, color0);
        break;
        case 10 :
        effects.fillTriangle(x1, y1, x1, y2, x2, y1, color);
        effects.fillTriangle(x2, y2, x2, y1, x1, y2, color0);
        break;
        case 11 :
        effects.fillTriangle(x1, y1, x1, y2, x2, y1, color);
        break;
        case 12 :
        effects.fillTriangle(x2, y2, x2, y1, x1, y2, color);
        break;
      }
    }

    void drawMode4(int x1, int x2, int x3, int y1, int y2, int y3, uint8_t color, uint8_t color0, int md) {
      switch(md) {
        case 0 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, 31, x1, y1, x2, y2, color0);
        break;
        case 1 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        break;
        case 2 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, 31, x1, y1, x2, y2, color0);
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x1, y2, color);
        effects.drawTriangle(CENTRE_X, 31, x1, y1, x1, y2, color0);
        break;
        case 3 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        effects.fillTriangle(CENTRE_X, 31, x2, y2, x3, y3, color0);
        break;
        case 4 :
        effects.fillTriangle(CENTRE_X, 31, x2, y2, x3, y3, color);
        effects.drawTriangle(CENTRE_X, 31, x2, y2, x3, y3, color0);
        break;
        case 5 :
        effects.drawTriangle(CENTRE_X, 31, x2, y2, x3, y3, color);
        break;
        case 6 :
        effects.drawLine(x2, y2, x1, y1, color);
        effects.drawLine(x1, y1, x3, y3, color);
        break;
        case 7 :
        effects.drawLine(x2, y2, x3, y3, color);
        break;
        case 8 :
        effects.drawLine(x2, y2, x3, y3, color);
        effects.drawLine(x1, y2, x3, y3, color);
        break;
        case 9 :
        effects.fillTriangle(x1, y1, x2, y2, x2, y1, color);
        effects.fillTriangle(x1, y1, x3, y3, x3, y1, color);
        effects.drawTriangle(x1, y1, x2, y2, x2, y1, color0);
        effects.drawTriangle(x1, y1, x3, y3, x3, y1, color0);
        break;
        case 10 :
        effects.fillTriangle(x3, y3, x3, y2, x2, y3, color);
        effects.fillTriangle(x2, y2, x2, y3, x3, y2, color);
        break;
      }
    }

    void drawMode5(int x1, int x2, int x3, int y1, int y2, int y3, uint8_t color, uint8_t color0, int md) {
      switch(md) {
        case 0 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, 31, x1, y1, x2, y2, color0);
        break;
        case 1 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        break;
        case 2 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x1, y2, color);
        effects.drawTriangle(CENTRE_X, 31, x1, y1, x1, y2, color0);
        break;
        case 3 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        effects.fillTriangle(CENTRE_X, 31, x2, y2, x3, y3, color0);
        break;
        case 4 :
        effects.fillTriangle(CENTRE_X, 31, x2, y2, x3, y3, color);
        effects.drawTriangle(CENTRE_X, 31, x2, y2, x3, y3, color0);
        break;
        case 5 :
        effects.drawTriangle(CENTRE_X, 31, x2, y2, x3, y3, color);
        break;
        case 6 :
        effects.drawLine(x2, y2, x1, y1, color);
        effects.drawLine(x1, y1, x3, y3, color);
        break;
        case 7 :
        effects.drawLine(x2, y2, x3, y3, color);
        break;
        case 8 :
        effects.drawLine(x2, y2, x3, y3, color);
        effects.drawLine(x1, y2, x3, y3, color0);
        break;
        case 9 :
        effects.fillTriangle(x1, y1, x2, y2, x2, y1, color);
        effects.fillTriangle(x1, y1, x3, y3, x3, y1, color0);
        break;
        case 10 :
        effects.fillTriangle(x3, y3, x3, y2, x2, y3, color);
        effects.fillTriangle(x2, y2, x2, y3, x3, y2, color);
        break;
      }
    }

    void drawMode6(int x1, int x2, int y1, int y2, uint8_t color, uint8_t color0, int md) {
      switch(md) {
        case 0 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, 31, x1, y1, x2, y2, color0);
        break;
        case 1 :
        effects.fillTriangle(CENTRE_X, 31, x1, y1, x2, y2, color);
        break;
        case 2 :
        effects.fillTriangle(x1, y1, x2, y2, x1, y2, color);
        effects.fillTriangle(x1, y1, x2, y2, x2, y1, color);
        break;
        case 3 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        break;
        case 4 :
        effects.fillTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color);
        effects.drawTriangle(CENTRE_X, CENTRE_Y, x1, y1, x2, y2, color0);
        break;
        case 5 :
        effects.fillTriangle(x1, y1, x2, y2, x1, y2, color);
        break;
        case 6 :
        effects.fillTriangle(x1, y1, x2, y2, x2, y1, color);
        break;
        case 7 :
        effects.drawLine(x1, y1, x2, y1, color);
        effects.drawLine(x1, y1, x1, y2, color0);
        effects.drawLine(x2, y2, x1, y2, color);
        effects.drawLine(x2, y2, x2, y1, color0);
        break;
        case 8 :
        effects.drawLine(x1, y1, x2, y2, color);
        break;
        case 9 :
        effects.drawLine(x1, y1, x1, y2, color);
        effects.drawLine(x2, y2, x1, y2, color0);
        break;
        case 10 :
        effects.fillTriangle(x1, y1, x1, y2, x2, y1, color);
        effects.fillTriangle(x2, y2, x2, y1, x1, y2, color0);
        break;
        case 11 :
        effects.fillTriangle(x1, y1, x1, 31, x2, 31, color);
        effects.fillTriangle(x2, y2, x2, 31, x1, 31, color);
        break;
        case 12 :
        effects.fillTriangle(x1, y1, x2, y2, x1, 31, color);
        effects.fillTriangle(x1, y1, x2, y2, x2, 31, color);
        break;
      }
    }

    void drawAudio1(int mod) {
        int dx = kMatrixWidth / bandCount;
      for (int i = 0; i < bandCount; i++) {
        int level = levels[i];
        int nextLevel = levels[i + 1];
        if (i == 15) nextLevel = levels[14];
        uint8_t color1 = level;
        uint8_t color2 = nextLevel;
        uint8_t y = kMatrixHeight - level - 1;
        uint8_t nextY = kMatrixHeight - nextLevel - 1;
        y = y >= kMatrixHeight ? kMatrixHeight - 1 : y;
        nextY = nextY >= kMatrixHeight ? kMatrixHeight - 1 : nextY;
        int x1 = i * dx;
        int x2 = i * dx + dx;
        drawMode1(x1, x2, y, nextY, color1, color2, mod);
      }
    }

    void drawAudio2(int mod) {
      float degreesPerLine = 360 / bandCount;
      for (int band = 0; band < bandCount; band++) {
        int level = levels[band]/2;
        int nextLevel = levels[band + 1]/2;
        if (band == 15) nextLevel = levels[14]/2;
        uint8_t color1 = level*2;
        uint8_t color2 = nextLevel*2;
        float radians = radians(angle);
        int x1 = CENTRE_X + level * 2  * sin(radians);
        int y1 = CENTRE_Y + level * cos(radians);
        radians = radians(angle - degreesPerLine/2);
        int x2 = CENTRE_X + level * 2 * sin(radians);
        int y2 = CENTRE_Y + level * cos(radians);
        radians = radians(angle + degreesPerLine/2);
        int x3 = CENTRE_X + nextLevel * 2 * sin(radians);
        int y3 = CENTRE_Y + nextLevel * cos(radians);
        drawMode2(x1, x2, x3, y1, y2, y3, color1, color2, mod);
        angle += degreesPerLine;
      }
      angle = 0;
    }

    void drawAudio3(int mod) {
      float degreesPerLine = 180 / bandCount;
      float angle = degreesPerLine - 90;
      for (int band = 0; band < bandCount; band++) {
        int level = levels[band];
        int nextLevel = levels[band + 1];
        if (band == 15) nextLevel = levels[14];
        uint8_t color1 = level*2;
        uint8_t color2 = nextLevel*2;
        float radians = radians(angle - degreesPerLine);
        int x1 = CENTRE_X + level * sin(radians);
        int y1 = 30 - level * cos(radians);
        radians = radians(angle);
        int x2 = CENTRE_X + nextLevel * sin(radians);
        int y2 = 30 - nextLevel * cos(radians);
        drawMode3(x1, x2, y1, y2, color1, color2, mod);
        angle += degreesPerLine;
      }
    }

    void drawAudio4(int mod) {
      float degreesPerLine = 180 / bandCount;
      for (int band = 0; band < bandCount; band++) {
        angle = (angle>90) ? (angle-180+degreesPerLine) : angle;
        int level = levels[band];
        int nextLevel = levels[band + 1];
        if (band == 15) nextLevel = levels[14];
        uint8_t color1 = level;
        uint8_t color2 = nextLevel;
        float radians = 135 + radians(angle);
        int x1 = CENTRE_X + level  * sin(radians);
        int y1 = 31 + level * cos(radians);
        radians = 135 + radians(angle + degreesPerLine/2);
        int x2 = CENTRE_X + nextLevel * sin(radians);
        int y2 = 31 + nextLevel * cos(radians);
        radians = 135 + radians(angle - degreesPerLine/2);
        int x3 = CENTRE_X + nextLevel * sin(radians);
        int y3 = 31 + nextLevel * cos(radians);
        drawMode4(x1, x2, x3, y1, y2, y3, color1, color2, mod);
        angle += degreesPerLine;
      }
      angle = 0;
    }

    void drawAudio5(int mod) {
      float degreesPerLine = 180 / bandCount;
      for (int band = 0; band < bandCount; band++) {
        int level = levels[band]/2;
        int nextLevel = levels[band + 1]/2;
        if (band == 15) nextLevel = levels[14]/2;
        uint8_t color1 = level;
        uint8_t color2 = nextLevel;
        float radians = 135 + radians(angle);
        int x1 = CENTRE_X + level * 2 * sin(radians);
        int y1 = 31 + level * cos(radians);
        radians = 135 + radians(angle + degreesPerLine/2);
        int x2 = CENTRE_X + nextLevel * 2 * sin(radians);
        int y2 = 31 + nextLevel * cos(radians);
        radians = 135 + radians(angle - degreesPerLine/2);
        int x3 = CENTRE_X + nextLevel * 2 * sin(radians);
        int y3 = 31 + nextLevel * cos(radians);
        drawMode5(x1, x2, x3, y1, y2, y3, color1, color2, mod);
        drawMode5(x1, x2, x3, 63-y1, 63-y2, 63-y3, color1, color2, mod);
        angle += degreesPerLine;
      }
      angle = 0;
    }

    void drawAudio6(int mod) {
        int dx = kMatrixWidth / bandCount;
      for (int i = 0; i < bandCount; i++) {
        int level = levels[i];
        int nextLevel = levels[i + 1];
        if (i == 15) nextLevel = levels[14];
        uint8_t color1 = level;
        uint8_t color2 = nextLevel;
        uint8_t y = kMatrixHeight - level - 1;
        uint8_t nextY = kMatrixHeight - nextLevel - 1;
        y = y >= kMatrixHeight ? kMatrixHeight - 1 : y;
        nextY = nextY >= kMatrixHeight ? kMatrixHeight - 1 : nextY;
        int x1 = i * dx;
        int x2 = i * dx + dx;
        drawMode6(x1, x2, y/2, nextY/2, color1, color2, mod);
        drawMode6(x1, x2, 31-(y/2), 31-(nextY/2), color1, color2, mod);
      }
    }

    int currentIndex = 0;

    int getCurrentIndex() {
      return currentIndex;
    }

    AudioP() {
      this->curtItem = itemP[currentIndex];
      for (int a = 0; a < P_COUNT; a++) {
        shufItems[a] = itemP[a];
      }
      shuffleItems();
    }

    void moveRandom(int step) {
      currentIndex += step;
      if (currentIndex >= P_COUNT) currentIndex = 0;
      else if (currentIndex < 0) currentIndex = P_COUNT - 1;
      curtItem = shufItems[currentIndex];
    }

    void shuffleItems() {
      for (int a = 0; a < P_COUNT; a++) {
        int r = random(a, P_COUNT);
        AudioPFunctionPointer temp = shufItems[a];
        shufItems[a] = shufItems[r];
        shufItems[r] = temp;
      }
    }

    char* Drawable::name = (char *)"Audio";

    void move(int step) {
      currentIndex += step;
      if (currentIndex >= P_COUNT) currentIndex = 0;
      else if (currentIndex < 0) currentIndex = P_COUNT - 1;
      moveTo(currentIndex);
    }

    void moveTo(int index) {
      currentIndex = index;
      curtItem = itemP[currentIndex];
    }

    unsigned int drawFrame() {
      (this->*curtItem)();
      return 0;
    }
    
    void listAudioPatterns() {
      Serial.println(F("{"));
      Serial.print(F("  \"count\": "));
      Serial.print(P_COUNT);
      Serial.println(",");
      Serial.println(F("  \"results\": ["));

      for (int i = 0; i < P_COUNT; i++) {
        Serial.print(F("    \""));
        Serial.print(i);
        if (i == P_COUNT - 1)
          Serial.println(F("\""));
        else
          Serial.println(F("\","));
      }

      Serial.println("  ]");
      Serial.println("}");
    }

    bool setAudioPattern(String name) {
      for (int i = 0; i < P_COUNT; i++) {
        if (name.toInt() == i) {
          moveTo(i);
          return true;
        }
      }

      return false;
    }

    bool setAudioPattern(int index) {
      if (index >= P_COUNT || index < 0)
        return false;
      moveTo(index);
      return true;
    }
};

#endif
