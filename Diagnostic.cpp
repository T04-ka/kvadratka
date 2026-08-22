// CДЕЛАТЬ ВЫВОД И ВВОД КОРНЕЙ ОТСОРТИРОВАННЫМИ, СДЕЛАТЬ ЗНАЧЕНИЯ ПО УМОЛЧАНИЮ NAN

void solveTest(void){

    RunTest(params, nroots_ref, x_ref);
}


bool RunTest(const int testN, const double *params, const Nroots nroots_ref, const double *roots_ref){

        double roots = {nan, nan};

        Nroots nroots = squareSolve(params, roots);

        //got and reference dont match
        if (!(nroots == nroots_ref && *roots == *roots_ref && *(roots+1) == *(roots_ref+1))) {

            _RED printf("Test %d FAILED. For parametrs a = %lg  b = %lg  c = %lg\n",
                                          testN, *params, *(params+1), *(params+2));
                                          
            //print "expected" stroke
            switch (nroots_ref){
                  
                case INF_ROOTS: {
                    
                    _RED printf("Expected: infinity roots");
                    break;
                }
                
                case ZERO_ROOTS: {
                
                    _RED printf("Expected: no roots");
                    break;
                }
                
                case ONE_ROOT: {
                    
                    _RED printf("Expected: 1 root x = %lg", *roots_ref);
                    break;
                }
                
                case TWO_ROOTS: {
                    
                    _RED printf("Expected: 2 roots x1 = %lg x2 = %lg", *roots_ref, *(roots_ref + 1));
                    break;
                }
                
                default : {}            
            }
            
            //print "got" stroke
            switch (nroots_ref){
                  
                case INF_ROOTS: {
                    
                    _RED printf("Got: infinity roots");
                    break;
                }
                
                case ZERO_ROOTS: {
                
                    _RED printf("Got: no roots");
                    break;
                }
                
                case ONE_ROOT: {
                    
                    _RED printf("Got 1 root x = %lg", *roots);
                    break;
                }
                
                case TWO_ROOTS: {
                    
                    _RED printf("     Got: 2 roots x1 = %lg x2 = %lg", *roots, *(roots + 1));
                    break;
                }
                
                default : {}            
            }
            
            return false;
        }
        
        //else: got and referense mach: OK
        return true;


}
