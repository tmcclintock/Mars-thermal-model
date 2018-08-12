#include <math.h>
#include <stdio.h>

/*Define various constants*/
#define epsilon 1. //emissivity of the surface
//note - should change epsilon to 0.8 if covered in C02 frost
#define sigma 5.67e-8 //W/m^2/K^4; stefan-boltzmann constant
#define rotation_rate 88775.2 //sec; rotation rate of Mars
#define A_ap 0.23  //surface albedo of Arcadia Planitia
#define A_up 0.12  //surface albedo of Utopia Planitia
#define A_co2 0.65 //surface albedo of CO2 frost
#define L_co2 580. //kJ/kg; latent heat of CO2 frost on the surface
#define D_reg 3e-4 //m^2/s; vapor diffusion coefficient through regolith
#define D_ice 1e-4 //m^2/s; vapor diffusion coefficient through porous ice
#define rho_ice 917. //kg/m^3; density of pure water ice

/*Define thermodynamic constants*/
#define k_rem 2.  //W/m/K; conductivity of rock end-member
#define k_iem 3.2 //W/m/K; conductivity of ice end-member
#define k_dry 0.023 //W/m/K; conductivity of dry regolith with phi_reg = 40% and TI = 196 J/m^2/k/s^0.5
#define k_reg 2.48 //W/m/K; conductivity of regolith with pore-filling ice with phi_reg = 40%
#define k_exi 2.14 //W/m/K; conductivity of excess ice with phi_ice = 30% and d = 3%
#define c_rem 837. //J/kg/K; heat capacity of rock end-member
#define c_iem 1540. //J/kg/K; heat capacity of ice end-member
#define rho_rem 3300. //kg/m^3; density of rock end-member
#define rho_iem 920. //kg/m^3; density of ice end-member
#define c_rho_dry 1657260. //kg/s^2/K/m; density times heat capacity of dry regolith
#define c_rho_reg 2223980. //kg/s^2/K/m; density times heat capacity of regolith with pore-filling ice
#define c_rho_exi 1032119. //kg/s^2/K/m; density times heap capacity of excess ice
#define TI_ap 196. //J/m^2/K/s^0.5; thermal inertial of Arcadia Planitia
#define TI_ap 195. //J/m^2/K/s^0.5; thermal inertial of Utopia Planitia

/*********************
Thermal model functions
 ********************/

/*Ice retreate per unit time.
  Returned units are m/s.
 */
double calc_ice_retreat_rate(double rho_vapor_zei, double rho_atmo, double rho_ice, double z_ei, double phi_ice, double dust_content){
  return D_reg * (rho_vapor_zei - rho_atmo) /
    (rho_ice * z_ei * (1 - phi_ice - dust_content));
}
