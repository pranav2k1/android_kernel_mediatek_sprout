/*
* Copyright (C) 2011-2014 MediaTek Inc.
* 
* This program is free software: you can redistribute it and/or modify it under the terms of the 
* GNU General Public License version 2 as published by the Free Software Foundation.
* 
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __MT_PWM_H__
#define __MT_PWM_H__

#include <mach/mt_typedefs.h>
#include <mach/mt_pwm_hal.h>

struct pwm_easy_config {
	U32 pwm_no;
	U32 duty;
	U32 clk_src;
	U32 clk_div;
	U16 duration;
	BOOL pmic_pad;
};
struct pwm_spec_config {
	U32 pwm_no;
	U32 mode;
	U32  clk_div;
	U32 clk_src;
	BOOL intr;
	BOOL pmic_pad;

	union {
		//for old mode
		struct _PWM_OLDMODE_REGS {
			U16 IDLE_VALUE;
			U16 GUARD_VALUE;
			U16 GDURATION;
			U16 WAVE_NUM;
			U16 DATA_WIDTH;
			U16 THRESH;
		}PWM_MODE_OLD_REGS;

		//for fifo mode
		struct _PWM_MODE_FIFO_REGS {
			U32 IDLE_VALUE;
			U32 GUARD_VALUE;
			U32 STOP_BITPOS_VALUE;
			U16 HDURATION;
			U16 LDURATION;
			U32 GDURATION;
			U32 SEND_DATA0;
			U32 SEND_DATA1;
			U32 WAVE_NUM;
		}PWM_MODE_FIFO_REGS;
/*
		//for memory mode
		struct _PWM_MODE_MEMORY_REGS {
			U32 IDLE_VALUE;
			U32 GUARD_VALUE;
			U32 STOP_BITPOS_VALUE;
			U16 HDURATION;
			U16 LDURATION;
			U16 GDURATION;
			U32  * BUF0_BASE_ADDR;
			U32 BUF0_SIZE;
			U16 WAVE_NUM;
		}PWM_MODE_MEMORY_REGS;

		//for RANDOM mode
		struct _PWM_MODE_RANDOM_REGS {
			U16 IDLE_VALUE;
			U16 GUARD_VALUE;
			U32 STOP_BITPOS_VALUE;
			U16 HDURATION;
			U16 LDURATION;
			U16 GDURATION;
			U32  * BUF0_BASE_ADDR;
			U32 BUF0_SIZE;
			U32 *BUF1_BASE_ADDR;
			U32 BUF1_SIZE;
			U16 WAVE_NUM;
			U32 VALID;
		}PWM_MODE_RANDOM_REGS;

		//for seq mode
		struct _PWM_MODE_DELAY_REGS {
			//U32 ENABLE_DELAY_VALUE;
			U16 PWM3_DELAY_DUR;
			U32 PWM3_DELAY_CLK;   //0: block clock source, 1: block/1625 clock source
			U16 PWM4_DELAY_DUR;
			U32 PWM4_DELAY_CLK;   
			U16 PWM5_DELAY_DUR;
			U32 PWM5_DELAY_CLK;
		}PWM_MODE_DELAY_REGS;
*/
	};	
};

S32 pwm_set_easy_config ( struct pwm_easy_config *conf);
S32 pwm_set_spec_config(struct pwm_spec_config *conf);

void mt_pwm_dump_regs(void);
void mt_pwm_disable(U32 pwm_no, BOOL pmic_pad);

/*----------3dLCM support-----------*/
/*
 base pwm2, select pwm3&4&5 same as pwm2 or inversion of pwm2
 */
void mt_set_pwm_3dlcm_enable(BOOL enable);

/*
 set "pwm_no" inversion of pwm2 or not, 
 pwm_no: only support PWM3/4/5
 */
void mt_set_pwm_3dlcm_inv(U32 pwm_no, BOOL inv);

#endif