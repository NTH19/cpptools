#pragma once
#include <unordered_map>
#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <iomanip>
#include <fstream>
using namespace std;


#define FLIGHT_FILE							"flight_data.txt"

#define STR_LEN								0x20


#define DEFAULT_TICKET_COUNT				200

typedef enum _tagFlightStatus
{
	STATUS_NORMAL,											
		STATUS_DELAY,											
		STATUS_CANCEL,											
		STATUS_COUNT
		
} FLIGHT_STATUS;

typedef enum _tagSortType
{
	SORT_NORMAL,											
		SORT_BY_PRICE,											
		SORT_BY_TIME,											
		SORT_BY_TICKET,											
		SORT_COUNT
		
} SORT_TYPE;

typedef struct _tagGuest
{
	char			strID[STR_LEN];							
	char			strName[STR_LEN];						
	
	int				nCount;
	
	_tagGuest()
	{
		memset(strID, 0, sizeof(strID));
		memset(strName, 0, sizeof(strName));
		
		nCount = 0;
	}
	
} GUEST, *LPGUEST;

typedef vector<GUEST>			GUESTS;
typedef deque<GUEST>            WGUESTS;
typedef struct _tagFlight
{
	char			strFlightID[STR_LEN];					
	char			strCompany[STR_LEN];					
	char			strStartCity[STR_LEN];					
	char			strEndCity[STR_LEN];					
	char			strTransitCity[STR_LEN];				
	
	struct tm       TakeoffTime;							
	struct tm       LandingTime;							
	
	int				nTicket;								
	
	int				nPrice;									
	
	GUESTS			Guests;									
	WGUESTS			WaitingGuests;							
	
	_tagFlight()
	{
		memset(strFlightID, 0, sizeof(strFlightID));
		memset(strFlightID, 0, sizeof(strFlightID));
		memset(strFlightID, 0, sizeof(strFlightID));
		memset(strFlightID, 0, sizeof(strFlightID));
		memset(strFlightID, 0, sizeof(strFlightID));
		
		memset(&TakeoffTime, 0, sizeof(TakeoffTime));
		memset(&LandingTime, 0, sizeof(LandingTime));
		
		nTicket = DEFAULT_TICKET_COUNT;
		
		nPrice = 0;
	}
	
} FLIGHT, *LPFLIGHT;