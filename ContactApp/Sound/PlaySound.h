
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include<MMSystem.h>

using namespace std;
void play()
{
	PlaySound(TEXT("Instructions_over_Voice\\welcome-to-voice-based-contact-search.wav"), NULL, SND_SYNC);
	
}

void audio_speak_the_word()
{
	PlaySound(TEXT("Instructions_over_Voice\\speak-the-contact-name.wav"), NULL, SND_SYNC);
}

void audio_is_it_correct()
{
	PlaySound(TEXT("Instructions_over_Voice\\is-it-correct.wav"), NULL, SND_SYNC);
}

void audio_do_you_want_to_search_contact_again()
{
	PlaySound(TEXT("Instructions_over_Voice\\do-you-want-to-search-contact-again"), NULL, SND_SYNC);
}

void audio_name_detected_as_name(int n)
{
	PlaySound(TEXT("Instructions_over_Voice\\the-name-detected-ismp3.wav"), NULL, SND_SYNC);
	Sleep(500);
	string name[]={"1Aman","2Chaitra","3---Divya","4Ema","5--Faizal","6--Gagan","7--Ira","8Karan","9Lilly","10Manish","11Preet","12--Rambo","13Sahil","14--Tanvi","15Urja","16Varun","Yes","No","Hold"};
	switch(n)
	{
		case 1: PlaySound(TEXT("Instructions_over_Voice\\Aman.wav"), NULL, SND_SYNC);
			break;
		case 2: PlaySound(TEXT("Instructions_over_Voice\\Chaitra.wav"), NULL, SND_SYNC);
			break;
		case 4: PlaySound(TEXT("Instructions_over_Voice\\Ema.wav"), NULL, SND_SYNC);
			break;
		case 3: PlaySound(TEXT("Instructions_over_Voice\\Divya.wav"), NULL, SND_SYNC);
			break;
		case 5: PlaySound(TEXT("Instructions_over_Voice\\Faizal.wav"), NULL, SND_SYNC);
			break;
		case 6: PlaySound(TEXT("Instructions_over_Voice\\Gagan.wav"), NULL, SND_SYNC);
			break;
		case 7: PlaySound(TEXT("Instructions_over_Voice\\Ira.wav"), NULL, SND_SYNC);
			break;
		case 8: PlaySound(TEXT("Instructions_over_Voice\\Karan.wav"), NULL, SND_SYNC);
			break;
		case 9: PlaySound(TEXT("Instructions_over_Voice\\Lily.wav"), NULL, SND_SYNC);
			break;
		case 10: PlaySound(TEXT("Instructions_over_Voice\\Manish.wav"), NULL, SND_SYNC);
			break;
		case 11: PlaySound(TEXT("Instructions_over_Voice\\Preet.wav"), NULL, SND_SYNC);
			break;
		case 12: PlaySound(TEXT("Instructions_over_Voice\\Rambo.wav"), NULL, SND_SYNC);
			break;
		case 13: PlaySound(TEXT("Instructions_over_Voice\\Sahil.wav"), NULL, SND_SYNC);
			break;
		case 14: PlaySound(TEXT("Instructions_over_Voice\\Tanvi.wav"), NULL, SND_SYNC);
			break;
		case 15: PlaySound(TEXT("Instructions_over_Voice\\Urja.wav"), NULL, SND_SYNC);
			break;
		case 16: PlaySound(TEXT("Instructions_over_Voice\\Varun.wav"), NULL, SND_SYNC);
			break;
		default: break;
	}
	return;
}


void audio_showing_details_of_name(int n)
{
	PlaySound(TEXT("Instructions_over_Voice\\showing-details-of.wav"), NULL, SND_SYNC);
	Sleep(500);
	string name[]={"1Aman","2Chaitra","3---Divya","4Ema","5--Faizal","6--Gagan","7--Ira","8Karan","9Lilly","10Manish","11Preet","12--Rambo","13Sahil","14--Tanvi","15Urja","16Varun","Yes","No","Hold"};
	switch(n)
	{
		case 1: PlaySound(TEXT("Instructions_over_Voice\\Aman.wav"), NULL, SND_SYNC);
			break;
		case 2: PlaySound(TEXT("Instructions_over_Voice\\Chaitra.wav"), NULL, SND_SYNC);
			break;
		case 4: PlaySound(TEXT("Instructions_over_Voice\\Ema.wav"), NULL, SND_SYNC);
			break;
		case 3: PlaySound(TEXT("Instructions_over_Voice\\Divya.wav"), NULL, SND_SYNC);
			break;
		case 5: PlaySound(TEXT("Instructions_over_Voice\\Faizal.wav"), NULL, SND_SYNC);
			break;
		case 6: PlaySound(TEXT("Instructions_over_Voice\\Gagan.wav"), NULL, SND_SYNC);
			break;
		case 7: PlaySound(TEXT("Instructions_over_Voice\\Ira.wav"), NULL, SND_SYNC);
			break;
		case 8: PlaySound(TEXT("Instructions_over_Voice\\Karan.wav"), NULL, SND_SYNC);
			break;
		case 9: PlaySound(TEXT("Instructions_over_Voice\\Lily.wav"), NULL, SND_SYNC);
			break;
		case 10: PlaySound(TEXT("Instructions_over_Voice\\Manish.wav"), NULL, SND_SYNC);
			break;
		case 11: PlaySound(TEXT("Instructions_over_Voice\\Preet.wav"), NULL, SND_SYNC);
			break;
		case 12: PlaySound(TEXT("Instructions_over_Voice\\Rambo.wav"), NULL, SND_SYNC);
			break;
		case 13: PlaySound(TEXT("Instructions_over_Voice\\Sahil.wav"), NULL, SND_SYNC);
			break;
		case 14: PlaySound(TEXT("Instructions_over_Voice\\Tanvi.wav"), NULL, SND_SYNC);
			break;
		case 15: PlaySound(TEXT("Instructions_over_Voice\\Urja.wav"), NULL, SND_SYNC);
			break;
		case 16: PlaySound(TEXT("Instructions_over_Voice\\Varun.wav"), NULL, SND_SYNC);
			break;
		default: break;
	}
	return;
}