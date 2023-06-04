Action()
{
	lr_start_transaction("UC01_Register");
	
	opensite();

	lr_think_time(5);

	create_new_acc();
	lr_think_time(5);

	lr_start_transaction("click_register");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountCreateRequest");

	lr_think_time(5);
	web_reg_find("Text/IC=New user created successfully.",
		LAST);
lr_save_string(lr_eval_string("{n1}{n2}{n3}{n4}"), "randomName");
	web_custom_request("AccountCreateRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/AccountCreateRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountCreateRequest xmlns=\"com.advantage.online.store.accountservice\">" 
		"<accountType>USER</accountType>" 
		"<address>{address}</address>" 
		"<allowOffersPromotion>true</allowOffersPromotion>" 
		"<cityName>{city}</cityName><countryId>Russia,ru</countryId>" 
		"<email>{email}</email>"
		"<firstName>{FirstName}</firstName>" 
		"<lastName>{LastName}</lastName>" 
		"<loginName>{randomName}</loginName>" 
		"<password>{password}</password>" 
		"<phoneNumber>{phone}</phoneNumber>" 
		"<stateProvince>{state}</stateProvince>" 
		"<zipcode>{zip}</zipcode></AccountCreateRequest></soap:Body></soap:Envelope>",
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLoginRequest");
	
	web_reg_save_param("userId",
		"LB/IC=<ns2:userId>",
		"RB/IC=<",
		LAST);

	web_reg_save_param("Authorization",
		"LB/IC=<ns2:t_authorization>",
		"RB/IC=<",
		LAST);
		
		

	

	web_custom_request("AccountLoginRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\">" 
		"<email>{email}</email>" 
		"<loginPassword>{password}</loginPassword>" 
		"<loginUser>{randomName}</loginUser>" 
		"</AccountLoginRequest></soap:Body></soap:Envelope>",
		LAST);

	web_set_sockets_option("INITIAL_AUTH", "BASIC");
	
		web_add_header("Authorization",
		"Basic {Authorization}");

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_url("{userId}", 
		"URL=https://www.advantageonlineshopping.com/order/api/v1/carts/{userId}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_register",LR_AUTO);
	lr_think_time(5);

	logout();
	lr_end_transaction("UC01_Register", LR_AUTO);

	return 0;
}