//
//  main.cpp
//  astronomy-calculator
//
//  Created by Justin on 4/8/15.
//  Copyright (c) 2015 Justin. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include "rapidjson/rapidjson.h"
#include "rapidjson/allocators.h"
#include "rapidjson/document.h"
#include "rapidjson/encodings.h"
#include "rapidjson/filestream.h"
#include "rapidjson/filereadstream.h"
#include "BeforeMain.h"

int option, search_option, calculate_option;

// Function prototypes
void calculate ();
void searchHrId();
void searchProper();
void searchHipparcos();
int searchOption();
double luminosity(double, double);
double distAU(double);
double brightness(double, double);

// Variable Declarations
int hip_store;
std::string hip_result = "";
bool assert_hip;
bool assert_spect;
int id_store;
std::string proper_store = "";
long double ra_store;
long double dec_store;
long double dist_store;
long double lum_store;
bool assert_lum;
double mag_store;
double absmag_store;
std::string spect_store = "";
std::string spect_result = "";
double distance_store;
double brightness_store;
double brightness_result;
std::string userproperentry;

// Constants
// 4 * pi
const long double fourpi = 4 * M_PI;

int main() {
    std::cout << "Astronomy Calculator!\n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Please select an option\n";
    std::cout << "1 to search:\n";
    std::cout << "2 to calculate:\n";
    std::cout << "3 to quit:\n";
    
    std::cin >> option;
    
    if (option == 1){

        std::cout << std::endl;
        std::cout << "Search HYG Stellar Database\n";
        std::cout << std::endl;
        std::cout << "Please select an option\n";
        std::cout << "1 to search by HYG catalog id:\n";
        std::cout << "2 search by proper name:\n";
        std::cout << "3 to search by Hipparcos id:\n";
        std::cout << "4 to quit:\n";
        
        std::cin >> search_option;
        
        if (search_option == 1){
            searchHrId();
        }
        else if (search_option == 2){
            searchProper();
        }
        else if (search_option == 3){
            searchHipparcos();
        }
        else if (search_option == 4){
            std::cout << "Thank you for using the Astronomy Calculator reference!\n";
            return 0;
        }
        else {
            std::cout << "You entered an invalid option.";
        }

    }
    else if (option ==   2){
    	calculate();
    }    
    else if (option == 3){
        std::cout << "Thank you for using Astronomy Calculator!\n";
        
        return 0;
    }
    else {
        std::cout << "You entered an invalid option.";
    }

    return 0;
}

void calculate ()
{
    std::cout << "You chose to calculate.\n";
}

void searchHrId()
{
    
    FILE * hygjson = fopen ("/Users/justin/Dropbox/school/cs-1410/final-project/git/astronomy-calculator/hygdata_v3.json" , "r");
    char readBuffer[65536];
    rapidjson::FileReadStream is(hygjson, readBuffer, sizeof(readBuffer));
    rapidjson::Document document;
    document.ParseStream(is);
    
    int useridentry;
    
    std::cout << "Please enter a HYG catalog id to search.\n";
    std::cin >> useridentry;

    const rapidjson::Value& dataArray = document["data"];
    
    for(rapidjson::Value::ConstMemberIterator it = dataArray.MemberBegin(); it != dataArray.MemberEnd(); it++) {
        
        id_store = it->value["id"].GetInt();
        ra_store = it->value["ra"].GetDouble();
        dec_store = it->value["dec"].GetDouble();
        dist_store = it->value["dist"].GetDouble();
        spect_store = it->value["spect"].GetString();
        lum_store = it->value["lum"].GetDouble();
        
        assert_hip = it->value["hip"].IsInt();
        
        if (assert_hip == true){
            hip_store = it->value["hip"].GetInt();
        }
        else {
            hip_store = 0;
        }
        
        assert_spect = spect_store.empty();
        
        if (assert_spect == true) {
            spect_result = "Not available";
        }
        else {
            spect_result = it->value["spect"].GetString();
        }
        
        assert_lum = it->value["lum"].IsDouble();
        
        if (assert_lum == true){
            lum_store = it->value["lum"].GetDouble();
        }
        else {
            lum_store = 0;
        }
        
            if (id_store == useridentry) {
                
                std::cout << "The HYG ID is: " << id_store << std::endl;
                std::cout << "The Hipparcos ID is: " << hip_store << std::endl;
                std::cout << "The Right Ascension is: " << ra_store << std::setprecision(10) << std::endl;
                std::cout << "The Declination is: " << dec_store << std::setprecision(10) << std::endl;
                std::cout << "The Distance in parsecs is: " << dist_store << std::setprecision(10) << std::endl;
                std::cout << "The Distance in AU is: " << distAU(dist_store) << std::setprecision(10) << std::endl;
                std::cout << "The Spectral Type is: " << spect_result << std::endl;
                std::cout << "The Luminosity is: "<< lum_store << std::setprecision(10) << std::endl;
                std::cout << "The Brightness in W/m^2 is: " << brightness(dist_store, lum_store) << std::setprecision(10) << std::endl;
                
                break;
            
            }
        
    }
    if (id_store != useridentry) {
        std::cout << "There is no record for your entry.\n";
    }

}

void searchHipparcos()
{
    
    FILE * hygjson = fopen ("/Users/justin/Dropbox/school/cs-1410/final-project/git/astronomy-calculator/hygdata_v3.json" , "r");
    char readBuffer[65536];
    rapidjson::FileReadStream is(hygjson, readBuffer, sizeof(readBuffer));
    rapidjson::Document document;
    document.ParseStream(is);
    
    int useridentry;
    
    std::cout << "Please enter a Hipparcos catalog id to search.\n";
    std::cin >> useridentry;
    
    const rapidjson::Value& dataArray = document["data"];
    
    for(rapidjson::Value::ConstMemberIterator it = dataArray.MemberBegin(); it != dataArray.MemberEnd(); it++) {
        
        id_store = it->value["id"].GetInt();
        ra_store = it->value["ra"].GetDouble();
        dec_store = it->value["dec"].GetDouble();
        dist_store = it->value["dist"].GetDouble();
        spect_store = it->value["spect"].GetString();
        lum_store = it->value["lum"].GetDouble();
        
        assert_hip = it->value["hip"].IsInt();
        
        if (assert_hip == true){
            hip_store = it->value["hip"].GetInt();
        }
        else {
            hip_store = 0;
        }
        
        assert_spect = spect_store.empty();
        
        if (assert_spect == true) {
            spect_result = "Not available";
        }
        else {
            spect_result = it->value["spect"].GetString();
        }
        
        assert_lum = it->value["lum"].IsDouble();
        
        if (assert_lum == true){
            lum_store = it->value["lum"].GetDouble();
        }
        else {
            lum_store = 0;
        }
        
        if (hip_store == useridentry) {
            
            std::cout << "The HYG ID is: " << id_store << std::endl;
            std::cout << "The Hipparcos ID is: " << hip_store << std::endl;
            std::cout << "The Right Ascension is: " << ra_store << std::setprecision(10) << std::endl;
            std::cout << "The Declination is: " << dec_store << std::setprecision(10) << std::endl;
            std::cout << "The Distance in parsecs is: " << dist_store << std::setprecision(10) << std::endl;
            std::cout << "The Distance in AU is: " << distAU(dist_store) << std::setprecision(10) << std::endl;
            std::cout << "The Spectral Type is: " << spect_result << std::endl;
            std::cout << "The Luminosity is: "<< lum_store << std::setprecision(10) << std::endl;
            
            break;
            
        }
    }
    if (hip_store != useridentry) {
        std::cout << "There is no Hipparcos record for your entry.\n";
    }
    
}


void searchProper()
{
    
    FILE * hygjson = fopen ("/Users/justin/Dropbox/school/cs-1410/final-project/git/astronomy-calculator/hygdata_v3.json" , "r");
    char readBuffer[65536];
    rapidjson::FileReadStream is(hygjson, readBuffer, sizeof(readBuffer));
    rapidjson::Document document;
    document.ParseStream(is);
    
    std::cout << "Please enter a proper name to search.\n";
    
//    std::getline(std::cin, userproperentry);

    
    std::cin.ignore();
    std::getline(std::cin, userproperentry);
    
    userproperentry[0] = toupper(userproperentry[0]);
    
    const rapidjson::Value& membersArray = document["data"];
    
    for(rapidjson::Value::ConstMemberIterator it = membersArray.MemberBegin(); it != membersArray.MemberEnd(); it++) {
        
        proper_store = it->value["proper"].GetString();
        id_store = it->value["id"].GetInt();
        ra_store = it->value["ra"].GetDouble();
        dec_store = it->value["dec"].GetDouble();
        dist_store = it->value["dist"].GetDouble();
        spect_store = it->value["spect"].GetString();
        lum_store = it->value["lum"].GetDouble();
        
        assert_hip = it->value["hip"].IsInt();
        
        if (assert_hip == true){
            hip_store = it->value["hip"].GetInt();
        }
        else {
            hip_store = 0;
        }
        
        assert_spect = spect_store.empty();
        
        if (assert_spect == true) {
            spect_result = "Not available";
        }
        else {
            spect_result = it->value["spect"].GetString();
        }
        
        assert_lum = it->value["lum"].IsDouble();
        
        if (assert_lum == true){
            lum_store = it->value["lum"].GetDouble();
        }
        else {
            lum_store = 0;
        }
        
        
        if (proper_store == userproperentry) {
           
            std::cout << "The Proper name is: " << proper_store << std::endl;
            std::cout << "The HYG ID is: " << id_store << std::endl;
            std::cout << "The Hipparcos ID is: " << hip_store << std::endl;
            std::cout << "The Right Ascension is: " << ra_store << std::setprecision(10) << std::endl;
            std::cout << "The Declination is: " << dec_store << std::setprecision(10) << std::endl;
            std::cout << "The Distance in parsecs is: " << dist_store << std::setprecision(10) << std::endl;
            std::cout << "The Distance in AU is: " << distAU(dist_store) << std::setprecision(10) << std::endl;
            std::cout << "The Spectral Type is: " << spect_result << std::endl;
            std::cout << "The Luminosity is: "<< lum_store << std::setprecision(10) << std::endl;
            
            break;
            
        }
        
    }
    
    if (proper_store != userproperentry) {
        std::cout << "Not in the database.\n";
    }
}


// Distance - convert to AU from parsecs
double distAU(double dist_store){
    
    long double distanceAU;
    
    distanceAU = dist_store * 3.262;
    
    return distanceAU;
}

// Brightness
double brightness(double lum, double dist){
    
    long double denom;
    
    if (lum_store != 0){
        
        lum = lum_store;
    }
    else {
        return 0;
    }
    
    dist = dist_store;
    
    denom = ( fourpi * ( pow(dist, 2.0) ) );
    
    brightness_result = lum / denom;
    
    return brightness_result;
}