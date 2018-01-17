/* Created by Language version: 6.2.0 */
/* NOT VECTORIZED */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define _threadargscomma_ /**/
#define _threadargs_ /**/
 
#define _threadargsprotocomma_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gmax _p[0]
#define i _p[1]
#define g _p[2]
#define m _p[3]
#define h _p[4]
#define ina _p[5]
#define mexp_val _p[6]
#define hexp_val _p[7]
#define Dm _p[8]
#define Dh _p[9]
#define _g _p[10]
#define _ion_ina	*_ppvar[0]._pval
#define _ion_dinadv	*_ppvar[1]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_FRT(void);
 static void _hoc_alpha(void);
 static void _hoc_beta(void);
 static void _hoc_faco(void);
 static void _hoc_ghkca(void);
 static void _hoc_iassign(void);
 static void _hoc_mh(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_nap", _hoc_setdata,
 "FRT_nap", _hoc_FRT,
 "alpha_nap", _hoc_alpha,
 "beta_nap", _hoc_beta,
 "faco_nap", _hoc_faco,
 "ghkca_nap", _hoc_ghkca,
 "iassign_nap", _hoc_iassign,
 "mh_nap", _hoc_mh,
 0, 0
};
#define FRT FRT_nap
#define alpha alpha_nap
#define beta beta_nap
#define faco faco_nap
#define ghkca ghkca_nap
 extern double FRT( double );
 extern double alpha( double , double );
 extern double beta( double , double );
 extern double faco( );
 extern double ghkca( double );
 /* declare global and static user variables */
#define Inf Inf_nap
 double Inf[2];
#define Tau Tau_nap
 double Tau[2];
#define cai cai_nap
 double cai = 0;
#define cao cao_nap
 double cao = 0;
#define erev erev_nap
 double erev = 55;
#define hexp hexp_nap
 double hexp = 0;
#define hq10 hq10_nap
 double hq10 = 0;
#define htemp htemp_nap
 double htemp = 0;
#define hbasetau hbasetau_nap
 double hbasetau = 0;
#define hvhalf hvhalf_nap
 double hvhalf = 0;
#define hbaserate hbaserate_nap
 double hbaserate = 0;
#define hgamma hgamma_nap
 double hgamma = 0;
#define hvalence hvalence_nap
 double hvalence = 0;
#define ki ki_nap
 double ki = 0.001;
#define mininf mininf_nap
 double mininf = 0.0001;
#define mexp mexp_nap
 double mexp = 3;
#define mq10 mq10_nap
 double mq10 = 3;
#define mtemp mtemp_nap
 double mtemp = 36;
#define mbasetau mbasetau_nap
 double mbasetau = 0.02;
#define mvhalf mvhalf_nap
 double mvhalf = -33.5;
#define mbaserate mbaserate_nap
 double mbaserate = 4.5;
#define mgamma mgamma_nap
 double mgamma = 0.5;
#define mvalence mvalence_nap
 double mvalence = 2;
#define vmin vmin_nap
 double vmin = -100;
#define vmax vmax_nap
 double vmax = 100;
#define vrest vrest_nap
 double vrest = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "erev_nap", "mV",
 "vmax_nap", "mV",
 "vmin_nap", "mV",
 "ki_nap", "mM",
 "cao_nap", "mM",
 "cai_nap", "mM",
 "gmax_nap", "umho",
 "i_nap", "mA/cm^2",
 "g_nap", "mho/cm^2",
 0,0
};
 static double delta_t = 1;
 static double h0 = 0;
 static double m0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "erev_nap", &erev_nap,
 "vrest_nap", &vrest_nap,
 "mvalence_nap", &mvalence_nap,
 "mgamma_nap", &mgamma_nap,
 "mbaserate_nap", &mbaserate_nap,
 "mvhalf_nap", &mvhalf_nap,
 "mbasetau_nap", &mbasetau_nap,
 "mtemp_nap", &mtemp_nap,
 "mq10_nap", &mq10_nap,
 "mexp_nap", &mexp_nap,
 "hvalence_nap", &hvalence_nap,
 "hgamma_nap", &hgamma_nap,
 "hbaserate_nap", &hbaserate_nap,
 "hvhalf_nap", &hvhalf_nap,
 "hbasetau_nap", &hbasetau_nap,
 "htemp_nap", &htemp_nap,
 "hq10_nap", &hq10_nap,
 "hexp_nap", &hexp_nap,
 "vmax_nap", &vmax_nap,
 "vmin_nap", &vmin_nap,
 "ki_nap", &ki_nap,
 "mininf_nap", &mininf_nap,
 "cao_nap", &cao_nap,
 "cai_nap", &cai_nap,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 "Inf_nap", Inf_nap, 2,
 "Tau_nap", Tau_nap, 2,
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"nap",
 "gmax_nap",
 0,
 "i_nap",
 "g_nap",
 0,
 "m_nap",
 "h_nap",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 11, _prop);
 	/*initialize range parameters*/
 	gmax = 0.03;
 	_prop->param = _p;
 	_prop->param_size = 11;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _nap_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 11, 3);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 nap /home/konstantinos/Desktop/NEURON/ncdemo/x86_64/nap.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96489.0;
 static double R = 8.31441;
static int _reset;
static char *modelname = "Kevin's Cvode modification to Borg Graham Channel Model";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int iassign();
static int mh(double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 () {_reset=0;
 {
   mh ( _threadargscomma_ v ) ;
   Dm = ( - m + Inf [ 0 ] ) / Tau [ 0 ] ;
   Dh = ( - h + Inf [ 1 ] ) / Tau [ 1 ] ;
   }
 return _reset;
}
 static int _ode_matsol1 () {
 mh ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( - 1.0 ) ) / Tau[0] )) ;
 Dh = Dh  / (1. - dt*( ( ( - 1.0 ) ) / Tau[1] )) ;
 return 0;
}
 /*END CVODE*/
 static int states () {_reset=0;
 {
   mh ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( - 1.0 ) ) / Tau[0])))*(- ( ( ( Inf[0] ) ) / Tau[0] ) / ( ( ( - 1.0 ) ) / Tau[0] ) - m) ;
    h = h + (1. - exp(dt*(( ( - 1.0 ) ) / Tau[1])))*(- ( ( ( Inf[1] ) ) / Tau[1] ) / ( ( ( - 1.0 ) ) / Tau[1] ) - h) ;
   }
  return 0;
}
 
static int  mh (  double _lv ) {
   double _la , _lb , _lj , _lmqq10 , _lhqq10 ;
 _lmqq10 = pow( mq10 , ( ( celsius - mtemp ) / 10. ) ) ;
   _lhqq10 = pow( hq10 , ( ( celsius - htemp ) / 10. ) ) ;
   {int  _lj ;for ( _lj = 0 ; _lj <= 1 ; _lj ++ ) {
     _la = alpha ( _threadargscomma_ _lv , ((double) _lj ) ) ;
     _lb = beta ( _threadargscomma_ _lv , ((double) _lj ) ) ;
     Inf [ _lj ] = _la / ( _la + _lb ) ;
     if ( Inf [ _lj ] < mininf ) {
       Inf [ _lj ] = 0.0 ;
       }
     
/*VERBATIM*/
    switch (_lj) {
      case 0:
      /* Make sure Tau is not less than the base Tau */
if ((Tau[_lj] = 1 / (_la + _lb)) < mbasetau) {
  Tau[_lj] = mbasetau;
}
Tau[_lj] = Tau[_lj] / _lmqq10;
break;
case 1:
if ((Tau[_lj] = 1 / (_la + _lb)) < hbasetau) {
  Tau[_lj] = hbasetau;
}
Tau[_lj] = Tau[_lj] / _lhqq10;
if (hexp==0) {
  Tau[_lj] = 1.; }
  break;
    }

 } }
    return 0; }
 
static void _hoc_mh(void) {
  double _r;
   _r = 1.;
 mh (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double alpha (  double _lv , double _lj ) {
   double _lalpha;
 if ( _lj  == 1.0 ) {
     if ( hexp  == 0.0 ) {
       _lalpha = 1.0 ;
       }
     else {
       _lalpha = hbaserate * exp ( ( _lv - ( hvhalf + vrest ) ) * hvalence * hgamma * FRT ( _threadargscomma_ htemp ) ) ;
       }
     }
   else {
     _lalpha = mbaserate * exp ( ( _lv - ( mvhalf + vrest ) ) * mvalence * mgamma * FRT ( _threadargscomma_ mtemp ) ) ;
     }
   
return _lalpha;
 }
 
static void _hoc_alpha(void) {
  double _r;
   _r =  alpha (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double beta (  double _lv , double _lj ) {
   double _lbeta;
 if ( _lj  == 1.0 ) {
     if ( hexp  == 0.0 ) {
       _lbeta = 1.0 ;
       }
     else {
       _lbeta = hbaserate * exp ( ( - _lv + ( hvhalf + vrest ) ) * hvalence * ( 1.0 - hgamma ) * FRT ( _threadargscomma_ htemp ) ) ;
       }
     }
   else {
     _lbeta = mbaserate * exp ( ( - _lv + ( mvhalf + vrest ) ) * mvalence * ( 1.0 - mgamma ) * FRT ( _threadargscomma_ mtemp ) ) ;
     }
   
return _lbeta;
 }
 
static void _hoc_beta(void) {
  double _r;
   _r =  beta (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double FRT (  double _ltemperature ) {
   double _lFRT;
 _lFRT = FARADAY * 0.001 / R / ( _ltemperature + 273.15 ) ;
   
return _lFRT;
 }
 
static void _hoc_FRT(void) {
  double _r;
   _r =  FRT (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double ghkca (  double _lv ) {
   double _lghkca;
 double _lnu , _lefun ;
 _lnu = _lv * 2.0 * FRT ( _threadargscomma_ celsius ) ;
   if ( fabs ( _lnu ) < 1.e-6 ) {
     _lefun = 1. - _lnu / 2. ;
     }
   else {
     _lefun = _lnu / ( exp ( _lnu ) - 1. ) ;
     }
   _lghkca = - FARADAY * 2.e-3 * _lefun * ( cao - cai * exp ( _lnu ) ) ;
   
return _lghkca;
 }
 
static void _hoc_ghkca(void) {
  double _r;
   _r =  ghkca (  *getarg(1) );
 hoc_retpushx(_r);
}
 
double faco (  ) {
   double _lfaco;
 _lfaco = ki / ( ki + cai ) ;
   
return _lfaco;
 }
 
static void _hoc_faco(void) {
  double _r;
   _r =  faco (  );
 hoc_retpushx(_r);
}
 
static int  iassign (  ) {
   i = g * ( v - erev ) ;
   ina = i ;
    return 0; }
 
static void _hoc_iassign(void) {
  double _r;
   _r = 1.;
 iassign (  );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol1 ();
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  h = h0;
  m = m0;
 {
   mh ( _threadargscomma_ v ) ;
   m = Inf [ 0 ] ;
   h = Inf [ 1 ] ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   if ( gmax  == 0.0 ) {
     g = 0. ;
     }
   else {
     hexp_val = 1.0 ;
     mexp_val = 1.0 ;
     if ( hexp > 0.0 ) {
       {int  _lindex ;for ( _lindex = 1 ; _lindex <= ((int) hexp ) ; _lindex ++ ) {
         hexp_val = h * hexp_val ;
         } }
       }
     if ( mexp > 0.0 ) {
       {int  _lindex ;for ( _lindex = 1 ; _lindex <= ((int) mexp ) ; _lindex ++ ) {
         mexp_val = m * mexp_val ;
         } }
       }
     g = gmax * mexp_val * hexp_val ;
     }
   iassign ( _threadargs_ ) ;
   }
 _current += ina;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
 double _break, _save;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _break = t + .5*dt; _save = t;
 v=_v;
{
 { {
 for (; t < _break; t += dt) {
 error =  states();
 if(error){fprintf(stderr,"at line 110 in file bg_cvode.inc:\n\n"); nrn_complain(_p); abort_run(error);}
 
}}
 t = _save;
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
_first = 0;
}
