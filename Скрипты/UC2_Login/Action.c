Action()
{
	lr_start_transaction("UC2_Login");
	
	opensite();
lr_think_time(5);
	lr_start_transaction("login");

	web_add_auto_header("Origin", 
		"https://www.advantageonlineshopping.com");
	web_reg_find("Text/IC=Login Successful",
		LAST);

	web_add_auto_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLoginRequest");
	web_reg_save_param("userId",
		"LB/IC=<ns2:userId>",
		"RB/IC=<",
		LAST);
	
	web_reg_save_param("Authorization",
		"LB/IC=<ns2:t_authorization>",
		"RB/IC=<",
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	

	web_custom_request("AccountLoginRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/AccountLoginRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\">" 
		"<email></email>" 
		"<loginPassword>{password}</loginPassword>" 
		"<loginUser>{login}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>",
		LAST);

	

	web_set_sockets_option("INITIAL_AUTH", "BASIC");

	web_revert_auto_header("Origin");
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_revert_auto_header("SOAPAction");

	web_revert_auto_header("X-Requested-With");

	web_url("{userId}", 
		"URL=https://www.advantageonlineshopping.com/order/api/v1/carts/{userId}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("login",LR_AUTO);
	lr_think_time(5);

	logout();
	lr_end_transaction("UC2_Login",LR_AUTO);

	return 0;
}