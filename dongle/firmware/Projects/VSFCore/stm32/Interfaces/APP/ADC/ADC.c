/**************************************************************************
 *  Copyright (C) 2008 - 2010 by Simon Qian                               *
 *  SimonQian@SimonQian.com                                               *
 *                                                                        *
 *  Project:    Versaloon                                                 *
 *  File:       ADC.c                                                     *
 *  Author:     SimonQian                                                 *
 *  Versaion:   See changelog                                             *
 *  Purpose:    SPI interface implementation file                         *
 *  License:    See license                                               *
 *------------------------------------------------------------------------*
 *  Change Log:                                                           *
 *      YYYY-MM-DD:     What(by Who)                                      *
 *      2008-11-07:     created(by SimonQian)                             *
 **************************************************************************/

#include "app_cfg.h"
#if INTERFACE_ADC_EN

#include "app_interfaces.h"
#include "ADC.h"

// AD0 -- AD2 : ADC3_4 -- ADC3_6
// AD3 : ADC1_6

vsf_err_t adc_init(uint8_t index)
{
	switch (index)
	{
	case 0:		
		core_interfaces.adc.init(2);
		core_interfaces.adc.init(0);
		return VSFERR_NONE;
	default:
		return VSFERR_NOT_SUPPORT;
	}
}

vsf_err_t adc_fini(uint8_t index)
{
	switch (index)
	{
	case 0:
		core_interfaces.adc.fini(2);
		core_interfaces.adc.fini(0);
		return VSFERR_NONE;
	default:
		return VSFERR_NOT_SUPPORT;
	}
}

vsf_err_t adc_config(uint8_t index, uint32_t clock_hz, uint8_t mode)
{
	switch (index)
	{
	case 0:
		core_interfaces.adc.config(2, clock_hz, mode);
		core_interfaces.adc.config(0, clock_hz, mode);
		return VSFERR_NONE;
	default:
		return VSFERR_NOT_SUPPORT;
	}
}

vsf_err_t adc_config_channel(uint8_t index, uint8_t channel, uint8_t cycles)
{
	switch (index)
	{
	case 0:
		if (channel <= 2)
		{
			return core_interfaces.adc.config_channel(2, channel + 4, cycles);
		}
		else if (3 == channel)
		{
			return core_interfaces.adc.config_channel(0, 6, cycles);
		}
	default:
		return VSFERR_NOT_SUPPORT;
	}
}

vsf_err_t adc_calibrate(uint8_t index, uint8_t channel)
{
	switch (index)
	{
	case 0:
		if (channel <= 2)
		{
			return core_interfaces.adc.calibrate(2, channel + 4);
		}
		else if (3 == channel)
		{
			return core_interfaces.adc.calibrate(0, 6);
		}
	default:
		return VSFERR_NOT_SUPPORT;
	}
}

vsf_err_t adc_start(uint8_t index, uint8_t channel)
{
	switch (index)
	{
	case 0:
		if (channel <= 2)
		{
			return core_interfaces.adc.start(2, channel + 4);
		}
		else if (3 == channel)
		{
			return core_interfaces.adc.start(0, 6);
		}
	default:
		return VSFERR_NOT_SUPPORT;
	}
}

vsf_err_t adc_isready(uint8_t index, uint8_t channel)
{
	switch (index)
	{
	case 0:
		if (channel <= 2)
		{
			return core_interfaces.adc.isready(2, channel + 4);
		}
		else if (3 == channel)
		{
			return core_interfaces.adc.isready(0, 6);
		}
	default:
		return VSFERR_NOT_SUPPORT;
	}
}

uint32_t adc_get(uint8_t index, uint8_t channel)
{
	switch (index)
	{
	case 0:
		if (channel <= 2)
		{
			return core_interfaces.adc.get(2, channel + 4);
		}
		else if (3 == channel)
		{
			return core_interfaces.adc.get(0, 6);
		}
	default:
		return 0;
	}
}

vsf_err_t adc_sample(uint8_t index, uint8_t channel, uint32_t *voltage)
{
	switch (index)
	{
	case 0:
		if (channel <= 2)
		{
			return core_interfaces.adc.sample(2, channel + 4, voltage);
		}
		else if (3 == channel)
		{
			return core_interfaces.adc.sample(0, 6, voltage);
		}
	default:
		return VSFERR_NOT_SUPPORT;
	}
}

#endif
