/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 19, 2019
 *      Author: Max Wayne
 */
#pragma once
#include <string>
#include <vector>
#include <memory>
#include "./includes/Watch.h"
#include "./includes/Smalltalk.h"
#include "./includes/constants.h"

Smalltalk::Smalltalk(std::string myNationality,int iPerson):nationality(myNationality),iPerson(iPerson), current_phrase(0){}

Smalltalk::~Smalltalk(void){}

std::string Smalltalk::saySomething(){

	this->populatePhrases();

	const int NUM_US_PHRASES = 5;
	const int NUM_BRIT_PHRASES = 7;
	const int NUM_DE_PHRASES = 10;
	if (this->nationality == BRIT){
		int index = this->current_phrase % NUM_BRIT_PHRASES;
		this->current_phrase++;
		return this->mySmallTalk[index];
	}
	else if (this->nationality == AMERICAN){
		int index = this->current_phrase % NUM_US_PHRASES;
		this->current_phrase++;
		return this->mySmallTalk[index];
	}
	else if (this->nationality == AMERICAN_DE){
		int index = this->current_phrase % NUM_DE_PHRASES;
		this->current_phrase++;
		return this->mySmallTalk[index];
	}

	const std::string fail = "Did not find nationality";
	return fail;
}

std::string Smalltalk::getTime(){
	if (!pWatch){
		return I_DO_NOT_HAVE_A_WATCH;
	}

	return pWatch->getTime();
}

std::unique_ptr<Watch>  Smalltalk::takeWatch(){
	std::unique_ptr<Watch> thisWatch;
	if (!this->pWatch){
		thisWatch = 0;;
	}
	thisWatch = std::move(this->pWatch);
	return thisWatch;
}

bool Smalltalk::giveWatch(std::unique_ptr<Watch> &pWatch){

	if (this->pWatch){
		return false;
	}
	this->pWatch = std::move(pWatch);
	return true;
}



