#include "precompiled.h"
#include "rehlds_tests_shared.h"
#include "cppunitlite/TestHarness.h"

#pragma warning(push)
#ifndef _WIN32
#pragma warning(disable : 1875)		// warning #1875: offsetof applied to non-POD (Plain Old Data) types is nonstandard
#endif // _WIN32

#define CHECK_STRUCT_SIZE(s,win_size,lin_size) {\
	int needOff = __isWindows ? win_size : lin_size; \
	UINT32_EQUALS("Bad size "#s"::", needOff, sizeof(s)); \
}

#define CHECK_STRUCT_OFFSET(s,f,win_off,lin_off) {\
	int needOff = __isWindows ? win_off : lin_off; \
	int realOff = offsetof(s, f); \
	UINT32_EQUALS("Bad offset "#s"::"#f, needOff, realOff); \
	}

TEST(StructOffsets, ReversingChecks, 5000)
{
	CHECK_STRUCT_OFFSET(client_t, active, 0, 0);
	CHECK_STRUCT_OFFSET(client_t, chokecount, 0x2558, 0x2448);
	CHECK_STRUCT_OFFSET(client_t, datagram, 0x25D8, 0x24C4);
	CHECK_STRUCT_OFFSET(client_t, m_VoiceStreams, 0x5018, 0x4EF8);
	CHECK_STRUCT_OFFSET(client_t, m_lastvoicetime, 0x5020, 0x4F00);
	CHECK_STRUCT_OFFSET(client_t, datagram_buf, 0x25EC, 0x24D8);
	CHECK_STRUCT_OFFSET(client_t, connection_started, 0x3590, 0x3478);

	//CHECK_STRUCT_SIZE(server_t, 0x46418, 0x4640C);

	printf("sizeof server_t: 0x%2X\n", sizeof(server_t));
	printf("sizeof CSteam3Server: 0x%2X\n", sizeof(CSteam3Server));
	//printf("offsetof CSteam3Server::m_SteamIDGS: 0x%2X\n", offsetof(CSteam3Server, m_SteamIDGS));

	//CHECK_STRUCT_OFFSET(CSteam3, m_bLogOnResult, 5, 5);
	//CHECK_STRUCT_OFFSET(CSteam3Server, m_bLogOnResult, 5, 5);

	//CHECK_STRUCT_OFFSET(CSteam3Server, m_bLanOnly, 0x86, 0x9E);
	//CHECK_STRUCT_OFFSET(CSteam3Server, m_SteamIDGS, 0x87, 0x9F);
}

#pragma warning( pop )
