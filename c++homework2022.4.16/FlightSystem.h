#pragma once
#include "Common.h"

class FlightSystem
{
public:
	
	bool LoadFromFile();
	bool SaveToFile();
	void AddFlight();
	void DelFlight();
	void ModFlight();
	void Delay();
	void BuyTicket();
	void RefundTicket();
	void SearchByFlight();
	void SearchByAddress();
	void SearchAllFlights();
	void SearchAllTickets();
	
protected:
	bool CheckFlightData();
	int GetFlightIndexByID(const char* pID);
	
	vector<FLIGHT>		m_Flights;
	
};

