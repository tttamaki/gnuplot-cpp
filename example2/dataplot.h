//
//  dataplot.h
//  gnuplot-cpp
//
//  Created by tamaki on 2013/12/26.
//  Copyright (c) 2013/12/26 tamaki. All rights reserved.
//

#ifndef __gnuplot_cpp__dataplot__
#define __gnuplot_cpp__dataplot__

#include <iostream>
#include <unistd.h>
#include <cmath>

#include <boost/assign/list_of.hpp> // for 'list_of()'

#include "gnuplot_i.hpp"



class multiPlotGnuplot {
protected:
    size_t length, dim;
    Gnuplot g1;
    std::vector< std::list<float> > t;
    std::vector<std::string> title;
    
public:
    void setLength(size_t _length){
        length = _length;
    };
    void setDim(size_t _dim){
        if(dim != _dim){
            dim = _dim;
            t.clear();
            t.resize(dim);
            title.clear();
            title.resize(dim);
        }
    }
    
    multiPlotGnuplot(size_t _length = 20, size_t _dim = 3){
        setLength(_length);
        g1.set_style("lines");
        setDim(_dim);
    };
    ~multiPlotGnuplot(){};
    
    void
    setTitles(const std::vector< std::string > &t){
        assert ( title.size() == dim);
        std::copy (t.begin(), t.end(), title.begin() );
    }
    
    void
    plot(const std::vector<float> &d){
        assert( d.size() == title.size() );
        assert( d.size() == t.size() );
        
        
        std::vector< std::list<float> > plotdata;
        
        std::vector<float>::const_iterator itd = d.begin();
        std::vector< std::list<float> >::iterator itt = t.begin();
        
        for(; itt != t.end(); itt++, itd++){
            (*itt).push_back( (*itd) );
            if( (*itt).size() > length)  (*itt).pop_front();
            plotdata.push_back( (*itt) );
        }
        
        g1.reset_plot();
        g1.plot_x(plotdata, title);
        
    };
    
    bool set_GNUPlotPath(const std::string &path){
        return g1.set_GNUPlotPath(path);
    }
    
};














#endif /* defined(__gnuplot_cpp__dataplot__) */
