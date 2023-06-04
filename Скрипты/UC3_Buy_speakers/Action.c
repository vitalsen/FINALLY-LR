Action()
{
	lr_start_transaction("UC3_Buy");
	
	opensite();
	lr_think_time(5);

	lr_start_transaction("login");

	web_add_header("Origin", 
		"https://www.advantageonlineshopping.com");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceAccountLoginRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(5);
	web_reg_find("Text/IC=Login Successful",
		LAST);
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
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\">" 
		"<email></email>" 
		"<loginPassword>{password}</loginPassword>" 
		"<loginUser>{login}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>",
		LAST);
	
	

	web_set_sockets_option("INITIAL_AUTH", "BASIC");
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_reg_save_param("sessionId",
		"LB/IC=\"sessionId\":\"",
		"RB/IC=\"",
		LAST);
	
	

	web_url("{userId}", 
		"URL=https://www.advantageonlineshopping.com/order/api/v1/carts/{userId}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("click_speakers");
	web_reg_find("Text/IC=SPEAKERS",
		LAST);

	web_url("products", 
		"URL=https://www.advantageonlineshopping.com/catalog/api/v1/categories/4/products", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_url("attributes", 
		"URL=https://www.advantageonlineshopping.com/catalog/api/v1/categories/attributes", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("category-page.html", 
		"URL=https://www.advantageonlineshopping.com/app/views/category-page.html", 
		"Resource=0", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_speakers",LR_AUTO);

	lr_start_transaction("find_speakers");
	

	web_url("20", 
		"URL=https://www.advantageonlineshopping.com/catalog/api/v1/products/20", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);
	web_reg_find("Text/IC=HP S9500 Bluetooth Wireless Speaker",
		LAST);

	web_url("products_2", 
		"URL=https://www.advantageonlineshopping.com/catalog/api/v1/categories/4/products", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("all_data", 
		"URL=https://www.advantageonlineshopping.com/catalog/api/v1/categories/all_data", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("product-page.html", 
		"URL=https://www.advantageonlineshopping.com/app/views/product-page.html", 
		"Resource=0", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("find_speakers",LR_AUTO);

	lr_start_transaction("add_to_cart");
	
	web_reg_find("Text/IC=productsInCart",
		LAST);
	
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_add_auto_header("Origin", 
		"https://www.advantageonlineshopping.com");

	lr_think_time(5);

	web_submit_data("414141", 
		"Action=https://www.advantageonlineshopping.com/order/api/v1/carts/{userId}/product/20/color/414141?quantity=1", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=sessionId", "Value={sessionId}", ENDITEM, 
		LAST);

	lr_end_transaction("add_to_cart",LR_AUTO);

	lr_start_transaction("chekout");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdRequest");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(5);

	web_custom_request("GetAccountByIdRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/GetAccountByIdRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {Authorization}</base64Token></GetAccountByIdRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");

	web_custom_request("GetAccountByIdNewRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/GetAccountByIdNewRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {Authorization}</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_reg_save_param("sessionId",
		"LB/IC=\"sessionId\":\"",
		"RB/IC=\"",
		LAST);

	web_url("{userId}_2", 
		"URL=https://www.advantageonlineshopping.com/order/api/v1/carts/{userId}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"https://www.advantageonlineshopping.com");

	web_custom_request("shippingcost", 
		"URL=https://www.advantageonlineshopping.com/#/orderPayment", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"seaddress\":{\"addressLine1\":" 
		"\"{adress}\",\"addressLine2\":\"\",\"city\":" 
		"\"{cityName}\",\"country\":\"us\",\"postalCode\":{zipcode},\"state\":{stateProvince},\"secustomerName\":{login},\"secustomerPhone\":{phoneNumber},\"senumberOfProducts\":1,\"setransactionType\":\"SHIPPING_COST\",\"sessionId\":\"{sessionId}\"}", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetAccountPaymentPreferencesRequest");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("GetAccountPaymentPreferencesRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/GetAccountPaymentPreferencesRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {Authorization}</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>", 
		LAST);

	web_revert_auto_header("Origin");

	web_url("orderPayment-page.html", 
		"URL=https://www.advantageonlineshopping.com/app/order/views/orderPayment-page.html", 
		"Resource=0", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceGetCountriesRequest");

	web_add_auto_header("Origin", 
		"https://www.advantageonlineshopping.com");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("GetCountriesRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/GetCountriesRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
		LAST);

	lr_end_transaction("chekout",LR_AUTO);
	lr_think_time(5);
	

	

	lr_start_transaction("pay_now");

	web_add_header("SOAPAction", 
		"com.advantage.online.store.accountserviceUpdateMasterCreditMethodRequest");

	lr_think_time(5);

	web_custom_request("UpdateMasterCreditMethodRequest", 
		"URL=https://www.advantageonlineshopping.com/accountservice/ws/UpdateMasterCreditMethodRequest", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=text/xml; charset=UTF-8", 
		"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><UpdateMasterCreditMethodRequest xmlns=\"com.advantage.online.store.accountservice\">" 
		"<userId>{userId}</userId>" 
		"<cardNumber>{cardNumber}</cardNumber>"
		"<expirationDate>{date}</expirationDate>" 
		"<cvvNumber>{cvv}</cvvNumber>" 
		"<customerName>{cardholdername}</customerName>"
		"<referenceId>{userId}</referenceId><base64Token>Basic {Authorization}</base64Token></UpdateMasterCreditMethodRequest></soap:Body></soap:Envelope>", 
		LAST);
	
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_revert_auto_header("X-Requested-With");
	web_reg_find("Text/IC=order completed successfully",
		LAST);
	

	

	web_custom_request("{userId}_4", 
		"URL=https://www.advantageonlineshopping.com/order/api/v1/orders/users/{userId}", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"orderPaymentInformation\":{\"Transaction_AccountNumber\":\"112987298763\",\"Transaction_Currency\":\"USD\",\"Transaction_CustomerPhone\":\"\",\"Transaction_MasterCredit_CVVNumber\":\"123\",\"Transaction_MasterCredit_CardNumber\":\"4886424244444444\",\"Transaction_MasterCredit_CustomerName\":\"vito\",\"Transaction_MasterCredit_ExpirationDate\":\"122027\",\"Transaction_PaymentMethod\":\"MasterCredit\",\"Transaction_ReferenceNumber\":0,\"Transaction_SafePay_Password\":\"\",\""
    "Transaction_SafePay_UserName\":\"\",\"Transaction_TransactionDate\":\"24052023\",\"Transaction_Type\":\"PAYMENT\"},\"orderShippingInformation\":{\"Shipping_Address_Address\":\"\",\"Shipping_Address_City\":\"\",\"Shipping_Address_CountryCode\":40,\"Shipping_Address_CustomerName\":\"VITLi7 \",\"Shipping_Address_CustomerPhone\":\"\",\"Shipping_Address_PostalCode\":\"\",\"Shipping_Address_State\":\"\",\"Shipping_Cost\":809.97,\"Shipping_NumberOfProducts\":3,\"Shipping_TrackingNumber\":0},\""
    "purchasedProducts\":[{\"hexColor\":\"414141\",\"productId\":20,\"quantity\":3,\"hasWarranty\":false}]}",
    LAST);
	
	web_add_header("Authorization",
		"Basic {Authorization}");

	web_custom_request("{userId}_4", 
		"URL=https://www.advantageonlineshopping.com/order/api/v1/carts/{userId}", 
		"Method=DELETE", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.advantageonlineshopping.com/", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("pay_now",LR_AUTO);

    //logout();
	lr_end_transaction("UC3_Buy",LR_AUTO);

	return 0;
}