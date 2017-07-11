
/* AD1938 Audio Codec  control library
*
* Copyright (c) 2017, Yasmeen Sultana
*
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice, development funding notice, and this permission
* notice shall be included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#ifndef _CONTROL_AD1938_H_
#define _CONTROL_AD1938_H_

#include "AudioControl.h"


#define AD1938_SPI_CLK_FREQ      1000000
#define AD1938_SPI_CHIP_SEL      7 /*teensy 3.6 gpio*/
#define AD1938_SPI_SCK           14 /*teensy 3.6 gpio*/
#define AD1938_RESET             17 /*teensy 3.6 gpio*/

#define AD1938_ENABLE_SERIAL_LOGS //enable serial logs

class AudioControlAD1938 : public AudioControl
{
public:
    bool init(void);/*( miso,mosi,sck,cs,rest pins)*/ 
	bool enable(void);
	bool disable(void);
	bool volume(float volume);
	bool adcMute(bool mute);
	bool dacMute(bool mute);
	bool configI2SSlave(void);//(48000,8 ,24,master)
	bool configI2SMaster(void);
	void readAllreg(void);
	bool inputSelect(int n) {
		return (n == 0) ? true : false;
	}
	bool inputLevel( float volume) {
		 return false;
	}
private:
	int ad1938_cs;
	int ad1938_rest;
	int ad1938_i2smode;
protected:
	bool spi_write_reg(unsigned char reg, unsigned char val);
	unsigned char spi_read_reg(unsigned char reg);
	bool isPllLocked();
	bool dacVolume(int dac_num,int volume);
	
};



#endif // !_CONTROL_AD1938_H_
