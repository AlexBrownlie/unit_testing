#include <iostream>
#include <fstream>
#include <string>
#include "gridworld.h"
#include "gridworld_route.h"


using namespace GPS;

const metres HorizontalGridUnit = 10000;
const metres VerticalGridUnit = 50;

/* Function to create a GPX route, given the name of the 
 * route and the path taken in GridWorld. */
void generateRoute(std::string, std::string);


/* Main function is used to generate all the routes needed by
 * my tests. If further tests were added it would be easy to 
 * generate new GPX logs. */

int main() {

    // Name of the route and the pathway taken in GridWorld are given as parameters
    generateRoute("twoPositionsIncline", "NM");
    generateRoute("twoPositionsDecline", "MN");
    generateRoute("threePositionsIncline", "KLM");
    generateRoute("threePositionsDecline", "MNO");
    generateRoute("fivePositionsNetIncline", "KLMSG");
    generateRoute("fivePositionsNetDecline", "GSMLK");
    
    return 0;
}


void generateRoute(std::string routeName, std::string pathTaken) {
    
    // Making a GridWorldRoute using a GridWorld with Clifton Campus as its start point
    GridWorldRoute route = GridWorldRoute(pathTaken, GridWorld(Earth::CliftonCampus, HorizontalGridUnit, VerticalGridUnit) );
    
    // Converting the GridWorldRoute to a GPX route
    std::string gpxRoute = route.toGPX();
    
    /* The following code opens/creates a file in the GPX logs with the name
     * given in the parameters, plus my student ID number. 
     * It then writes the GPX route to the file and then closes it. */
    std::ofstream routeFile;
    routeFile.open("../logs/GPX/routes/"+ routeName + "N0724106.gpx");
    routeFile << gpxRoute;
    routeFile.close();
    
}









