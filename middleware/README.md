## Middleware in embedded systems 
1. Abstracts the OS and hardware for applications running on Embedded Systems 
2. It acts as a bridge, that simplifies complex hardware and ensures that mulitple software can run on the hardware reliability and work together reliabily
3. It can be part of 
    - system s/w layer 
    - os and middleware together 
    - device-driver and middleware 
4. middleware functions
    - expose API 
    - communication management 
    - resource management 
    - standardized interfaces 
    - security and safety 
5. Types of middleware elements:
    - Message Oriented middleware 
    - Object Request Brokers
    - Remote Procedure Calls
    - Database access, network protocols above device driver layer 
6. Broadly middleware classified into general purpose middleware and market specific middleware(standard based software, automative ecu) 
7. Families of middleware
	- Automotive : AUTOSAR 
	- IIOT 
	- Consumer electronics
8. Middleware is not just like a library you call, but rather a process or service that is executed continuously in a OS from  startup or if the service is called. 
9. Example, say i wanted to send messages or an application needs to sent message, then it can call or use the middleware services that run on linux os and does the job 
10. Embedded software stack can be service oriented or signal oriented 
11. C++ is preferred for middleware development 




