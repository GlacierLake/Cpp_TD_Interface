# Cpp_TD_Interface
## The high-speed interface to connect TD Ameritrade API's with C++.
******************************************************************

The goal of this project is that at end, you will have all the tools you need to access TD Ameritrade's API for developers given that you have an account, a client key, a refresh token, and your callback url. With the evolution of programming languages C++ was chosen for its speed and efficiency; cross-platform while not the primary goal is set to work with both windows and linux, though linux has not undergone any testing as of yet. Another important part of this project is to incorporate new standards of coding which begins with **C++ 20 Modules** with extensions .ixx and .ifc, these types of files are optimized for efficiency, you can learn more about modules here: 

https://docs.microsoft.com/en-us/cpp/cpp/modules-cpp?view=msvc-160

Another part of this projects goal is to have minimum dependencies, with the major two as of right now only being libCurl for networking and a simple url encoder, *which has been upgraded to a module file*, of which the original source code can be found here:

libCurl: https://github.com/curl/curl

url encoder: https://github.com/tkislan/url_encoder

The project is being built on Visual Studio so that everyone who is currently working on the project can be on the same page when testing, such as enabling experimental features and such. As of reading this, the priority focus is to simply create the functions without focusing all effort on cross-platform reliability, in the end the module files should be able to run on compilers such as gcc. We currently are not testing for this and are primarily focused on making sure it works in Visual C++ first before moving onto next steps.

**********************************************************************************************************************************************************************************

While more dependecines may be soon to come, we are trying to limit and optimize storage so that speed will become the priority. The end goal of this project is to have a series of module files containing all RESTful requests to TDA's server, a complete websocket interface library to TDA, and some cleanup and data conversion functions. This project library is intended for use of production, such that it would be capable to be implemented into spaces where one would need fast and efficient code, for more data science oriented uses we recommend taking a look at the matlab interface where the data can be readily availiable so that one can spend less time worried about code and more time focusing on the data extraction and setting up quantitative functions.

***********************************************************************************************************************************************************************************

NOTE: While we are aware of the Schwab-TD acquisition and are concerned of the projects validity in days to come, we will continue to work with TD's interface until such time comes that it will officially be declared cancelled.
