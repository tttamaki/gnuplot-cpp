//
//  dataplot.cpp
//  gnuplot-cpp
//
//  Created by tamaki on 2013/12/26.
//  Copyright (c) 2013/12/26 tamaki. All rights reserved.
//


#include "dataplot.h"



int main ( int argc, char **argv )
{
    


    multiPlotGnuplot<float> g1(20, 2), g2(20, 3); // (length, plots)
    g1.set_GNUPlotPath("/opt/local/bin");
    g2.set_GNUPlotPath("/opt/local/bin");

    
    {
        std::vector< std::string > gtitle;
        gtitle = boost::assign::list_of("sin(x)")("cos(x)");
        g1.setTitles(gtitle);
        gtitle = boost::assign::list_of("x")("2x")("3x+2");
        g2.setTitles(gtitle);
    }
    
    
    for (int x = 0; x < 10; x++) {
        
        
        std::vector<float> data1, data2;
        data1 = boost::assign::list_of( sin(x) ) ( cos(x) ) ;
        data2 = boost::assign::list_of( x ) ( 2*x ) ( 3*x+2 ) ;
        
        g1.plot( data1 );
        g2.plot( data2 );
        
        sleep(1);
        
    }
    
    std::cout << "data1 " << std::endl << g1 << std::endl;
    std::cout << "data2 " << std::endl << g2 << std::endl;
    
    return 0;
}
