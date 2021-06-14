module;
#pragma once

#include <iostream>;
#include "curl/curl.h"
#include <fstream>

export module TDAPI;

//imported c header files as modules
import "stdio.h";
import "stdlib.h";

//import module url_encoder
import url_encoder;


class td {
	private:
		
		//the struct that will contain all of the client details
		const static struct client_struct {
			std::string client_id = " ";
			std::string refresh_token = " ";
			std::string redirect_uri = " ";
			std::string account_id = " ";
		}client;

		
		static const std::string accesstoken;

		
		std::string postAccessToken() {
			//post
			// will get the Bearer Access Token given that the proper credentials are valid
			//if the credentials are invalid, it will shoot back an error
			
			CURL* curl = curl_easy_init();	//Label the request to an easy request to make it less complicated
			CURLcode res; //define res as a CURLcode which will automatically be assigned when the task determines what it needs to do

			curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); 

			//set data in "vectorized format", so that it can optimized for efficiency
			std::string data = { "&grant_type=refresh_token&refresh_token=" + UrlEncoder::Encode(client.refresh_token) + "&access_type=&code=&client_id=" + client.client_id + "%40AMER.OAUTHAP&redirect_uri=" };
			
			/*NOTE: the following code is likely inefficient since behind the scenes(i.e. in the actual LibCURL Library), 
			LibCURL has the ability to automatically determine what type of requests you are making and how to do it, 
			but there are manual ways to set it,so that LibCURL does not have to spend all that time checking*/
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
			curl_easy_setopt(curl, CURLOPT_URL, "https://api.tdameritrade.com/v1/oauth2/token");
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);

			/*res returns as a JSON, but will not be a string as seen earlier it is an automatically determined CURLcode.
			There will need to be a chunk of code that converts res to a string then read what we want out of the JSON,
			There are three options to do this, build a set of for loops for every JSON we ever recieve, build a speed-oriented
			JSON Library, or find a speed-oriented JSON Library.*/



			return "s";


		};
		
		/*Need to make a series of classes to get the Client Credentials from the JSON, perhaps using a map rather than create an
		individual function for each necessary client detail; will be looked into*/
		std::string getClientId() {
			std::fstream credentials;
			credentials.open("credentials.json");
			if (!credentials) {
				std::ofstream my_file("credentials.json");
			}
			else {
				credentials << "{\"ConsumerKey\" : \"\", \"RefreshToken\" : \"\", \"CallbackURL\" : \"\", \"AccountID\" : \"\", \"RefreshTime\" : \"\"}";
				credentials.close();
			}

			
		};
	
		//following code is commented out, so that rest of code can be compiled without receiving errors
		//when working on new functions, simply uncomment code
		/*
		std::string getRefreshToken() {

		};

		std::string getRedirectUrl() {

		};

		std::string getAccountId() {

		};
		*/

	public:
/*
		//orders
		std::string cancelOrder(std::string s1) {
			//delete
		};
		std::string getOrder() {
			//get
		};
		std::string getOrdersByPath() {
			//get
		};
		std::string getOrdersByQuery() {
			//get
		};
		std::string placeOrder() {
			//post
		};
		std::string replaceOrder() {
			//put
		};

		//saved orders
		std::string createSavedOrder() {
			//post
		};
		std::string deleteSavedOrder() {
			//delete
		};
		std::string getSavedOrder() {
			//get
		};
		std::string getSavedOrdersbyPath() {
			//get
		};
		std::string replaceSavedOrder() {
			//put
		};

		//accounts
		std::string getAccount() {
			//get
		};
		std::string getAccounts() {
			//get
		};
		
		//instruments
		std::string searchInstruments() {
			//get
		};
		std::string getInstrument() {
			//get
		};

		//market hours
		std::string getHoursforMultipleMarkets() {
			//get
		};
		std::string getHoursforSingleMarket() {
			//get
		};

		//movers
		std::string getMovers() {

		};

		//options chains
		std::string getOptionsChain() {
			//get
		};

		//price history
		std::string getPriceHistory() {
			//get
		};

		//quotes
		std::string getQuote() {
			//get
		};
		std::string getQuotes() {
			//get
		};

		//transaction history
		std::string getTransaction() {
			//get
		};
		std::string getTransactions() {
			//get
		};

		//user info & preferences
		std::string getPreferences() {
			//get
		};
		std::string getStreamerSubscriptionKeys() {
			//get
		};
		std::string getUserPrincipals() {
			//get
		};
		std::string updatePreferences() {
			//put
		};

		//watchlist
		std::string createWatchlist() {
			//post
		};
		std::string deleteWatchlist() {
			//delete
		};
		std::string getWatchlist() {
			//get
		};
		std::string getWatchlistforMultipleAccounts() {
			//get
		};
		std::string getWatchlistforSingleAccount() {
			//get
		};
		std::string replaceWatchlist() {
			//put
		};
		std::string updateWatchlist() {
			//patch
		};

		*/
};