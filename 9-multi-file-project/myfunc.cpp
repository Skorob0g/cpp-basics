#include "myheader.hpp"
void badsort(double * a, int n){                                                                            
    for (int j = 0; j < n; j++)                                                                             
        for (int i = 1; i < n - j; i++)                                                                     
            if ((fabs(a[i - 1]) < EPS) && (fabs(a[i]) > EPS))                                               
                std::swap(a[i - 1], a[i]);                                                                       
}
