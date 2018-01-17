NEURON {  POINT_PROCESS GABAb }

PARAMETER {
  Cdur	= 85	(ms)		: transmitter duration (rising phase)
  Alpha	= 0.016	(/ms mM)	: forward (binding) rate
  Beta	= 0.0047 (/ms)		: backward (unbinding) rate
  Erev	= -90	(mV)		: reversal potential
}

INCLUDE "netcon.inc"

:** GABAAf
