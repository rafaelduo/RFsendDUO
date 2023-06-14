/*
	name=RFsendDUO
	version=1.0.0
	license=FREE
	author=Rafael Guerreiro <rafael@duo.eng.br>
	maintainer=Rafael Guerreiro <rafael@duo.eng.br>
	sentence=Envia comandos RF (Logica Ladder for Logica C++).
	paragraph=The RFsendDUO library.
	category=Variable Manipulation
	url=https://github.com/rafaelDUO/RFsendDUO
	repository=https://github.com/rafaelDUO/RFsendDUO.git
	architectures=*
*/

#ifndef RFsendDUO_h
#define RFsendDUO_h
#include "arduino.h"

class RFsendDUO
{
	public:
		explicit RFsendDUO(uint16_t enable_tx, uint16_t data_tx);
		void begin();
		void send(const uint16_t buf[], const uint16_t len);
		
	protected:
	uint16_t enable_tx_pin;
	uint16_t data_tx_pin;
};
#endif