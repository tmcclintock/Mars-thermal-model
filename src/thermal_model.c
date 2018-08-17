#include "thermal_model.h"

/*********************
Thermal model functions
 ********************/

/*Ice retreate per unit time.
  Returned units are m/s.
 */
double calc_ice_retreat_rate(double rho_vapor_zei, double rho_atmo, double z_ei, double phi_ice, double dust_content){
  return D_reg * (rho_vapor_zei - rho_atmo) /
    (rho_ice * z_ei * (1 - phi_ice - dust_content));
}

int main(){
  printf("Compiled and ran.\n");
}
