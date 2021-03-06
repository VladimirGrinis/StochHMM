//
//  simpleTrellis.h

//Copyright (c) 2007-2012 Paul C Lott 
//University of California, Davis
//Genome and Biomedical Sciences Facility
//UC Davis Genome Center
//Ian Korf Lab
//Website: www.korflab.ucdavis.edu
//Email: lottpaul@gmail.com
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of
//this software and associated documentation files (the "Software"), to deal in
//the Software without restriction, including without limitation the rights to
//use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//the Software, and to permit persons to whom the Software is furnished to do so,
//subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


#ifndef SIMPLETRELLIS_H
#define SIMPLETRELLIS_H

#include <vector>
#include <iostream>
#include "basicTrellis.h"
#include "trellisCells.h"
#include "stochMath.h"
#include <stdlib.h>
namespace StochHMM{



    //!\def std::vector<std::vector<simpleCell> >  simpleTable;
    typedef std::vector<std::vector<simpleCell> >  simpleTable;


    //!\class simpleTrellis
    //!Description: simpleTrellis - derived from basicTrellis class                                                           
    //!Contains basic trellis - made from simpleCell class;
    
    class simpleTrellis :public basicTrellis{
    public:
        simpleTrellis(model*,sequences*);
        
        void print();
        std::string stringify();

        
        void calcViterbi();
        void calcNthViterbi(size_t);
        void calcForwardViterbi();
        void calcForward();
        void calcBackward();
       
        void calcEndViterbi();
        void calcNthEndViterbi(size_t);
        void calcEndForward();
        void calcEndForwardViterbi();
        void calcPosterior();

        //void setPosition(int,int);
        void setViterbi(double&);
        void setNthViterbi(double&);

        void setForward(double&);
        void setBackward(double&);
        void setPtr(int);

        //void setPosition(int,int);
        void setViterbi(size_t, size_t, double&);
        void setForward(size_t, size_t, double&);
        void setBackward(size_t, size_t, double&);
        void setPtr(size_t, size_t, int);
        
        //Return value at current position
        int getPtr(void);
        double& getViterbi();
        double& getForward();
        double& getBackward();
        
        //Return value at particular position and state
        int getPtr(size_t,size_t);
        double& getViterbi(size_t,size_t);
        double& getForward(size_t,size_t);
        double& getBackward(size_t,size_t);
        //void finalize(){return;};
            
        void traceback(traceback_path&);
        void traceback(traceback_path&,size_t);

        void traceStochViterbi(traceback_path&);
        void traceStochForward(traceback_path&);
        
        //vector<simpleCell>& operator[](int i){return (*trell)[i];};
        //traceback_path* stochTraceback()=0;
    private:
        
        size_t currentColumnSize;
        size_t currentColumnPos;
        size_t currentRowPos;
        
        simpleTable trell;
        simpleCell ending;
        
    };

}
#endif  /*SIMPLETRELLIS_H*/