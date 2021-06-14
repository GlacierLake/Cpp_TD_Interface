
#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#include "curl/curl.h"

//#include "url_encoder.h"

import url_encoder;


int main(){
struct client_struct {
			std::string client_id;
			std::string refresh_token;
			std::string redirect_uri;
			std::string account_id;
		};

		
			client_struct client;
			client.client_id = "";
			client.refresh_token = "";
			client.redirect_uri = "";
			client.account_id = "";
			
			CURL* curl = curl_easy_init();
			CURLcode res;
			
			curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
			
			std::string data = {"&grant_type=refresh_token&refresh_token=" + UrlEncoder::Encode(client.refresh_token) + "&access_type=&code=&client_id=" + client.client_id + "%40AMER.OAUTHAP&redirect_uri="};
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
			curl_easy_setopt(curl, CURLOPT_URL, "https://api.tdameritrade.com/v1/oauth2/token");
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);

			std::cout << res << std::endl;
			return 0;


		}
		