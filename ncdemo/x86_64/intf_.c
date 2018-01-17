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
#define tauAM _p[0]
#define tauNM _p[1]
#define tauGA _p[2]
#define tauGB _p[3]
#define invl _p[4]
#define WINV _p[5]
#define ahpwt _p[6]
#define tauahp _p[7]
#define tauRR _p[8]
#define refrac _p[9]
#define Vbrefrac _p[10]
#define RRWght _p[11]
#define VTH _p[12]
#define VTHC _p[13]
#define VTHR _p[14]
#define Vblock _p[15]
#define nbur _p[16]
#define tbur _p[17]
#define VGBdel _p[18]
#define rebound _p[19]
#define offsetGB _p[20]
#define RMP _p[21]
#define STDAM _p[22]
#define STDNM _p[23]
#define STDGA _p[24]
#define Vm _p[25]
#define VAM _p[26]
#define VNM _p[27]
#define VGA _p[28]
#define VGB _p[29]
#define AHP _p[30]
#define VGBa _p[31]
#define t0 _p[32]
#define tGB _p[33]
#define tg _p[34]
#define twg _p[35]
#define refractory _p[36]
#define xloc _p[37]
#define yloc _p[38]
#define zloc _p[39]
#define trrs _p[40]
#define WEX _p[41]
#define cbur _p[42]
#define invlt _p[43]
#define oinvl _p[44]
#define rebob _p[45]
#define spck _p[46]
#define _tsav _p[47]
#define _nd_area  *_ppvar[0]._pval
#define sop	*_ppvar[2]._pval
#define _p_sop	_ppvar[2]._pval
 
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
 static int hoc_nrnpointerindex =  2;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_DVIDSeed();
 static double _hoc_ESINo();
 static double _hoc_EXPo();
 static double _hoc_EXP();
 static double _hoc_allspck();
 static double _hoc_adjlist();
 static double _hoc_col();
 static double _hoc_chk();
 static double _hoc_clrvspks();
 static double _hoc_clrdvi();
 static double _hoc_callback();
 static double _hoc_callhoc();
 static double _hoc_coop();
 static double _hoc_dbx();
 static double _hoc_esinr();
 static double _hoc_floc();
 static double _hoc_fflag();
 static double _hoc_fini();
 static double _hoc_freedvi();
 static double _hoc_finishdvi();
 static double _hoc_finishdvir();
 static double _hoc_flag();
 static double _hoc_global_fini();
 static double _hoc_global_init();
 static double _hoc_getconv();
 static double _hoc_getdvi();
 static double _hoc_invlset();
 static double _hoc_initwrec();
 static double _hoc_initrec();
 static double _hoc_invlflag();
 static double _hoc_initinvl();
 static double _hoc_initjttr();
 static double _hoc_initvspks();
 static double _hoc_id();
 static double _hoc_jitrec();
 static double _hoc_jitcondiv();
 static double _hoc_jitcon();
 static double _hoc_jttr();
 static double _hoc_lof();
 static double _hoc_mkdvi();
 static double _hoc_oobpr();
 static double _hoc_pskshowtable();
 static double _hoc_popspk();
 static double _hoc_probejcd();
 static double _hoc_pgset();
 static double _hoc_prune();
 static double _hoc_pathgrps();
 static double _hoc_patha2b();
 static double _hoc_pid();
 static double _hoc_qclr();
 static double _hoc_qsz();
 static double _hoc_qstats();
 static double _hoc_resetall();
 static double _hoc_recfree();
 static double _hoc_recclr();
 static double _hoc_rddvi();
 static double _hoc_rates();
 static double _hoc_record();
 static double _hoc_recspk();
 static double _hoc_recini();
 static double _hoc_recflag();
 static double _hoc_randspk();
 static double _hoc_reset();
 static double _hoc_shock();
 static double _hoc_spkcnt();
 static double _hoc_scsv();
 static double _hoc_sprob();
 static double _hoc_setdvi();
 static double _hoc_setdviv();
 static double _hoc_setdvir();
 static double _hoc_svdvi();
 static double _hoc_spkstats2();
 static double _hoc_spkoutf();
 static double _hoc_spkstats();
 static double _hoc_shift();
 static double _hoc_thrh();
 static double _hoc_type();
 static double _hoc_test();
 static double _hoc_trvsp();
 static double _hoc_turnoff();
 static double _hoc_vinset();
 static double _hoc_vecname();
 static double _hoc_varnum();
 static double _hoc_vers();
 static double _hoc_vinflag();
 static double _hoc_wwfree();
 static double _hoc_wwszset();
 static double _hoc_wrc();
 static double _hoc_wrec();
 static double _hoc_wrecord();
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "DVIDSeed", _hoc_DVIDSeed,
 "ESINo", _hoc_ESINo,
 "EXPo", _hoc_EXPo,
 "EXP", _hoc_EXP,
 "allspck", _hoc_allspck,
 "adjlist", _hoc_adjlist,
 "col", _hoc_col,
 "chk", _hoc_chk,
 "clrvspks", _hoc_clrvspks,
 "clrdvi", _hoc_clrdvi,
 "callback", _hoc_callback,
 "callhoc", _hoc_callhoc,
 "coop", _hoc_coop,
 "dbx", _hoc_dbx,
 "esinr", _hoc_esinr,
 "floc", _hoc_floc,
 "fflag", _hoc_fflag,
 "fini", _hoc_fini,
 "freedvi", _hoc_freedvi,
 "finishdvi", _hoc_finishdvi,
 "finishdvir", _hoc_finishdvir,
 "flag", _hoc_flag,
 "global_fini", _hoc_global_fini,
 "global_init", _hoc_global_init,
 "getconv", _hoc_getconv,
 "getdvi", _hoc_getdvi,
 "invlset", _hoc_invlset,
 "initwrec", _hoc_initwrec,
 "initrec", _hoc_initrec,
 "invlflag", _hoc_invlflag,
 "initinvl", _hoc_initinvl,
 "initjttr", _hoc_initjttr,
 "initvspks", _hoc_initvspks,
 "id", _hoc_id,
 "jitrec", _hoc_jitrec,
 "jitcondiv", _hoc_jitcondiv,
 "jitcon", _hoc_jitcon,
 "jttr", _hoc_jttr,
 "lof", _hoc_lof,
 "mkdvi", _hoc_mkdvi,
 "oobpr", _hoc_oobpr,
 "pskshowtable", _hoc_pskshowtable,
 "popspk", _hoc_popspk,
 "probejcd", _hoc_probejcd,
 "pgset", _hoc_pgset,
 "prune", _hoc_prune,
 "pathgrps", _hoc_pathgrps,
 "patha2b", _hoc_patha2b,
 "pid", _hoc_pid,
 "qclr", _hoc_qclr,
 "qsz", _hoc_qsz,
 "qstats", _hoc_qstats,
 "resetall", _hoc_resetall,
 "recfree", _hoc_recfree,
 "recclr", _hoc_recclr,
 "rddvi", _hoc_rddvi,
 "rates", _hoc_rates,
 "record", _hoc_record,
 "recspk", _hoc_recspk,
 "recini", _hoc_recini,
 "recflag", _hoc_recflag,
 "randspk", _hoc_randspk,
 "reset", _hoc_reset,
 "shock", _hoc_shock,
 "spkcnt", _hoc_spkcnt,
 "scsv", _hoc_scsv,
 "sprob", _hoc_sprob,
 "setdvi", _hoc_setdvi,
 "setdviv", _hoc_setdviv,
 "setdvir", _hoc_setdvir,
 "svdvi", _hoc_svdvi,
 "spkstats2", _hoc_spkstats2,
 "spkoutf", _hoc_spkoutf,
 "spkstats", _hoc_spkstats,
 "shift", _hoc_shift,
 "thrh", _hoc_thrh,
 "type", _hoc_type,
 "test", _hoc_test,
 "trvsp", _hoc_trvsp,
 "turnoff", _hoc_turnoff,
 "vinset", _hoc_vinset,
 "vecname", _hoc_vecname,
 "varnum", _hoc_varnum,
 "vers", _hoc_vers,
 "vinflag", _hoc_vinflag,
 "wwfree", _hoc_wwfree,
 "wwszset", _hoc_wwszset,
 "wrc", _hoc_wrc,
 "wrec", _hoc_wrec,
 "wrecord", _hoc_wrecord,
 0, 0
};
#define DVIDSeed DVIDSeed_INTF
#define EXP EXP_INTF
#define allspck allspck_INTF
#define adjlist adjlist_INTF
#define col col_INTF
#define dbx dbx_INTF
#define esinr esinr_INTF
#define floc floc_INTF
#define fflag fflag_INTF
#define flag flag_INTF
#define getconv getconv_INTF
#define getdvi getdvi_INTF
#define invlset invlset_INTF
#define invlflag invlflag_INTF
#define id id_INTF
#define jttr jttr_INTF
#define pathgrps pathgrps_INTF
#define pid pid_INTF
#define qsz qsz_INTF
#define qstats qstats_INTF
#define rddvi rddvi_INTF
#define recflag recflag_INTF
#define spkcnt spkcnt_INTF
#define scsv scsv_INTF
#define setdviv setdviv_INTF
#define setdvir setdvir_INTF
#define svdvi svdvi_INTF
#define shift shift_INTF
#define thrh thrh_INTF
#define type type_INTF
#define vinset vinset_INTF
#define varnum varnum_INTF
#define vinflag vinflag_INTF
#define wwfree wwfree_INTF
#define wwszset wwszset_INTF
#define wrc wrc_INTF
#define wrec wrec_INTF
 extern double DVIDSeed( );
 extern double EXP( double );
 extern double allspck( );
 extern double adjlist( );
 extern double col( );
 extern double dbx( );
 extern double esinr( double );
 extern double floc( );
 extern double fflag( );
 extern double flag( );
 extern double getconv( );
 extern double getdvi( );
 extern double invlset( );
 extern double invlflag( );
 extern double id( );
 extern double jttr( );
 extern double pathgrps( );
 extern double pid( );
 extern double qsz( );
 extern double qstats( );
 extern double rddvi( );
 extern double recflag( );
 extern double spkcnt( );
 extern double scsv( );
 extern double setdviv( );
 extern double setdvir( );
 extern double svdvi( );
 extern double shift( double );
 extern double thrh( );
 extern double type( );
 extern double vinset( );
 extern double varnum( );
 extern double vinflag( );
 extern double wwfree( );
 extern double wwszset( );
 extern double wrc( );
 extern double wrec( );
 /* declare global and static user variables */
#define Bb Bb_INTF
 double Bb = 0;
#define DELMIN DELMIN_INTF
 double DELMIN = 1e-05;
#define DEAD_DIV DEAD_DIV_INTF
 double DEAD_DIV = 1;
#define ESIN ESIN_INTF
 double ESIN = 0;
#define EGB EGB_INTF
 double EGB = -30;
#define EGA EGA_INTF
 double EGA = -15;
#define ENM ENM_INTF
 double ENM = 90;
#define EAM EAM_INTF
 double EAM = 65;
#define FLAG FLAG_INTF
 double FLAG = 0;
#define Gn Gn_INTF
 double Gn = 0;
#define GPkd GPkd_INTF
 double GPkd = 100;
#define PATHMEASURE PATHMEASURE_INTF
 double PATHMEASURE = 0;
#define Psk Psk_INTF
 double Psk = 0;
#define RES RES_INTF
 double RES = 0;
#define WVAR WVAR_INTF
 double WVAR = 0.2;
#define installed installed_INTF
 double installed = 0;
#define jrtm jrtm_INTF
 double jrtm = -1;
#define jrtime jrtime_INTF
 double jrtime = -1;
#define jrsvd jrsvd_INTF
 double jrsvd = 10000;
#define jrsvn jrsvn_INTF
 double jrsvn = 10000;
#define mg mg_INTF
 double mg = 1;
#define nsw nsw_INTF
 double nsw = 0;
#define nxt nxt_INTF
 double nxt = 0;
#define pathlen pathlen_INTF
 double pathlen = 0;
#define pathtytarg pathtytarg_INTF
 double pathtytarg = 0;
#define pathidtarg pathidtarg_INTF
 double pathidtarg = -1;
#define pathend pathend_INTF
 double pathend = 0;
#define pathbeg pathbeg_INTF
 double pathbeg = 0;
#define prnum prnum_INTF
 double prnum = -1;
#define rebeg rebeg_INTF
 double rebeg = 0;
#define seadsetting seadsetting_INTF
 double seadsetting = 0;
#define slowset slowset_INTF
 double slowset = 0;
#define savclock savclock_INTF
 double savclock = 0;
#define seaddvioff seaddvioff_INTF
 double seaddvioff = 9.1021e-122;
#define seedstep seedstep_INTF
 double seedstep = 44340;
#define subsvint subsvint_INTF
 double subsvint = 0;
#define stopoq stopoq_INTF
 double stopoq = 0;
#define spkht spkht_INTF
 double spkht = 50;
#define tmax tmax_INTF
 double tmax = 0;
#define tauGBGP tauGBGP_INTF
 double tauGBGP = 50;
#define usetable usetable_INTF
 double usetable = 1;
#define verbose verbose_INTF
 double verbose = 1;
#define vdt vdt_INTF
 double vdt = 0.1;
#define wwht wwht_INTF
 double wwht = 10;
#define wwwid wwwid_INTF
 double wwwid = 10;
#define wGBGP wGBGP_INTF
 double wGBGP = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_INTF", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tauGBGP_INTF", "ms",
 "wGBGP_INTF", "ms",
 "tauAM", "ms",
 "tauNM", "ms",
 "tauGA", "ms",
 "tauGB", "ms",
 "invl", "ms",
 "tauahp", "ms",
 "tauRR", "ms",
 "refrac", "ms",
 "Vbrefrac", "ms",
 0,0
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "tauGBGP_INTF", &tauGBGP_INTF,
 "wGBGP_INTF", &wGBGP_INTF,
 "GPkd_INTF", &GPkd_INTF,
 "wwwid_INTF", &wwwid_INTF,
 "wwht_INTF", &wwht_INTF,
 "vdt_INTF", &vdt_INTF,
 "mg_INTF", &mg_INTF,
 "EAM_INTF", &EAM_INTF,
 "ENM_INTF", &ENM_INTF,
 "EGA_INTF", &EGA_INTF,
 "EGB_INTF", &EGB_INTF,
 "spkht_INTF", &spkht_INTF,
 "prnum_INTF", &prnum_INTF,
 "nsw_INTF", &nsw_INTF,
 "rebeg_INTF", &rebeg_INTF,
 "subsvint_INTF", &subsvint_INTF,
 "jrsvn_INTF", &jrsvn_INTF,
 "jrsvd_INTF", &jrsvd_INTF,
 "jrtime_INTF", &jrtime_INTF,
 "jrtm_INTF", &jrtm_INTF,
 "seedstep_INTF", &seedstep_INTF,
 "seaddvioff_INTF", &seaddvioff_INTF,
 "DEAD_DIV_INTF", &DEAD_DIV_INTF,
 "WVAR_INTF", &WVAR_INTF,
 "stopoq_INTF", &stopoq_INTF,
 "PATHMEASURE_INTF", &PATHMEASURE_INTF,
 "verbose_INTF", &verbose_INTF,
 "seadsetting_INTF", &seadsetting_INTF,
 "pathidtarg_INTF", &pathidtarg_INTF,
 "DELMIN_INTF", &DELMIN_INTF,
 "nxt_INTF", &nxt_INTF,
 "RES_INTF", &RES_INTF,
 "ESIN_INTF", &ESIN_INTF,
 "Gn_INTF", &Gn_INTF,
 "Bb_INTF", &Bb_INTF,
 "Psk_INTF", &Psk_INTF,
 "tmax_INTF", &tmax_INTF,
 "savclock_INTF", &savclock_INTF,
 "slowset_INTF", &slowset_INTF,
 "FLAG_INTF", &FLAG_INTF,
 "installed_INTF", &installed_INTF,
 "pathbeg_INTF", &pathbeg_INTF,
 "pathend_INTF", &pathend_INTF,
 "pathtytarg_INTF", &pathtytarg_INTF,
 "pathlen_INTF", &pathlen_INTF,
 "usetable_INTF", &usetable_INTF,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 static void _destructor(Prop*);
 static void _constructor(Prop*);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"INTF",
 "tauAM",
 "tauNM",
 "tauGA",
 "tauGB",
 "invl",
 "WINV",
 "ahpwt",
 "tauahp",
 "tauRR",
 "refrac",
 "Vbrefrac",
 "RRWght",
 "VTH",
 "VTHC",
 "VTHR",
 "Vblock",
 "nbur",
 "tbur",
 "VGBdel",
 "rebound",
 "offsetGB",
 "RMP",
 "STDAM",
 "STDNM",
 "STDGA",
 0,
 "Vm",
 "VAM",
 "VNM",
 "VGA",
 "VGB",
 "AHP",
 "VGBa",
 "t0",
 "tGB",
 "tg",
 "twg",
 "refractory",
 "xloc",
 "yloc",
 "zloc",
 "trrs",
 "WEX",
 "cbur",
 "invlt",
 "oinvl",
 "rebob",
 "spck",
 0,
 0,
 "sop",
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 48, _prop);
 	/*initialize range parameters*/
 	tauAM = 10;
 	tauNM = 300;
 	tauGA = 10;
 	tauGB = 300;
 	invl = 100;
 	WINV = 0;
 	ahpwt = 0;
 	tauahp = 10;
 	tauRR = 6;
 	refrac = 5;
 	Vbrefrac = 20;
 	RRWght = 0.75;
 	VTH = -45;
 	VTHC = -45;
 	VTHR = -45;
 	Vblock = -20;
 	nbur = 1;
 	tbur = 2;
 	VGBdel = 0;
 	rebound = 0.01;
 	offsetGB = 0;
 	RMP = -65;
 	STDAM = 0;
 	STDNM = 0;
 	STDGA = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 48;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 if (!nrn_point_prop_) {_constructor(_prop);}
 
}
 static void _initlists();
 
#define _tqitem &(_ppvar[3]._pvoid)
 static void _net_receive(Point_process*, double*, double);
 static void _net_init(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _intf__reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,(void*)0, (void*)0, (void*)0, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 	register_destructor(_destructor);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_prop_size(_mechtype, 48, 4);
 add_nrn_artcell(_mechtype, 3);
 add_nrn_has_net_event(_mechtype);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_init[_mechtype] = _net_init;
 pnt_receive_size[_mechtype] = 5;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 INTF /home/konstantinos/Desktop/NEURON/ncdemo/x86_64/intf_.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_Psk;
 static double *_t_RES;
 static double *_t_ESIN;
 static double *_t_Bb;
 static double *_t_Gn;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int ESINo(double);
static int EXPo(double);
static int _f_coop(double);
static int _f_rates(double);
static int _f_ESINo(double);
static int _f_EXPo(double);
static int _f_popspk(double);
static int chk(double);
static int clrvspks();
static int clrdvi();
static int callback(double);
static int callhoc();
static int coop(double);
static int fini();
static int freedvi();
static int finishdvi();
static int finishdvir();
static int global_fini();
static int global_init();
static int initwrec();
static int initrec();
static int initinvl();
static int initjttr();
static int initvspks();
static int jitrec();
static int jitcondiv();
static int jitcon(double);
static int lof();
static int mkdvi();
static int oobpr();
static int pskshowtable();
static int popspk(double);
static int probejcd();
static int pgset();
static int prune();
static int patha2b();
static int qclr();
static int resetall();
static int recfree();
static int recclr();
static int rates(double);
static int record();
static int recspk(double);
static int recini();
static int randspk();
static int reset();
static int shock();
static int sprob();
static int setdvi();
static int spkstats2(double);
static int spkoutf();
static int spkstats();
static int test();
static int trvsp();
static int turnoff();
static int vecname();
static int vers();
static int wrecord(double);
 static void _n_coop(double);
 static void _n_rates(double);
 static void _n_ESINo(double);
 static void _n_EXPo(double);
 static void _n_popspk(double);
 
/*VERBATIM*/
#include "misc.h"
static int ctt(unsigned int, char**);
static int setdvi2(double*,double*,int,int);

#define PI 3.141592653589793115997963468544
#define nil 0
#define CTYPp 20 // CTYPp>CTYPi from labels.hoc
#define SOP (((id0*) _p_sop)->vp)
#define IDP (*((id0**) &(_p_sop)))
#define NSW 20  // just store voltages
#define NSV 8  // 7 state variables (+ 1 for time)
#define FOFFSET 100 // flag offset for net_receive()
#define WRNUM 5  // a single INTF can store into this many ww field vecs
#define DELM(X,Y) (*(pg->delm+(X)*CTYPi+(Y)))
#define DELD(X,Y) (*(pg->deld+(X)*CTYPi+(Y)))
#define DVG(X,Y) ((int)*(pg->dvg+(X)*CTYPi+(Y)))
#define WMAT(X,Y,Z) (*(pg->wmat+(X)*CTYPi*STYPi+(Y)*STYPi+(Z)))
#define WD0(X,Y,Z)  (*(pg->wd0 +(X)*CTYPi*STYPi+(Y)*STYPi+(Z)))
#define NUMC(X) (*(pg->numc+(X)))
#define HVAL(X) (*(hoc_objectdata[(hoc_get_symbol((X)))->u.oboff]._pval))
#define HPTR(X) (hoc_objectdata[(hoc_get_symbol((X)))->u.oboff]._pval)

typedef struct VPT {
 unsigned int  id;
 unsigned int  size;
 unsigned int  p;
 void*    vv[NSV];
 double* vvo[NSV];
} vpt;

typedef struct POSTGRP { // postsynaptic group
  double *dvg; double *delm; double *deld; double *ix; double *ixe; double *wmat; double *wd0;
  double *numc;
  struct POSTGRP *next;
} postgrp;

typedef struct ID0 {
  vpt     *vp;
  postgrp *pg;
  float    wscale[WRNUM];
  Point_process **dvi; // each cell has a divergence list
  double *del;        // each syn has its own intrinsic delay
  unsigned char *sprob;    // each syn has a firing probability 0-255->0-1
  unsigned int dvt;
  unsigned int  id;
  unsigned int col;
  unsigned int rvb;
  unsigned int rvi;
  unsigned int spkcnt;
  unsigned int blkcnt;
  int rve;
  char   wreci[WRNUM]; // since use -1 as a flag
  char   errflag;
  // type -> vbr MUST REMAIN unbroked BLOCK -- see flag()
  // when adding flags also augment iflags, iflnum
  // only use first 3 letters with flag() -- see iflags
  unsigned char     type;  // | 
  unsigned char     inhib; // | 
  unsigned char     record;// |
  unsigned char     wrec;  // |
  unsigned char     jttr;  // |
  unsigned char     input; // |
  unsigned char     vinflg;// |
  unsigned char     invl0; // |
  unsigned char     jcn;   // |
  unsigned char     dead;  // |
  unsigned char     vbr;   // |
           char     dbx;   // |
           char     flag;  // |
  // end BLOCK
} id0;

// globals -- range vars must be malloc'ed in the CONSTRUCTOR
static vpt *vp; // vp, pg, ip are used as temporary pointers
static id0 *ip, *qp, *rp;
static postgrp *pg;
static Object *ce, *CTYP;
static Point_process *pmt, *tpnt;
static char *name;
static Symbol* cbsv;
// iflags string use to find flags -- note that only 1st 3 chars are used to identify
static char iflags[100]="typ inh rec wre jtt inp vin inv jcn dea vbr dbx fla"; 
static char iflnum=13, iflneg=11, errflag;      // turn on after generating an error message
static int  vspn;
static double *isp, *vsp, *wsp, *jsp, *invlp;
static double *lop(Object *ob, unsigned int i); // accessed by all INTF
static double *jrid, *jrtv;
static void   *jridv, *jrtvv;
static unsigned int jtpt,jtmax,jrmax;
static unsigned long int jri,jrj;
static unsigned long int spktot, eventtot;
static double vii[NSV];   // temp storage
static unsigned int wwpt,wwsz,wwaz,cesz; // pointer, size for shared ww vectors
static unsigned int sead, spikes[CTYPp], blockcnt[CTYPp]; // 'sead' vs global 'seed'/ used elsewhere
static unsigned int AMo[CTYPp],NMo[CTYPp],GAo[CTYPp],GBo[CTYPp]; // count overages for types
static char* CNAME[CTYPp]; // 20 should be > CTYPi
static int cty[CTYPp], process;
static int CTYN, CTYPi, STYPi, dscrsz; // from labels.hoc
static double qlimit, *dscr;
FILE *wf1, *wf2, *tf;
void*    ww[NSW];
double* wwo[NSW];
static int AM=0, NM=1, GA=2, GB=3, SU=3, IN=4, DP=2; // from labels.hoc
static double wts[10],hsh[10];  // for jitcons to use as a junk pointer
static int spkoutf2();
 
static int  reset (  ) {
   Vm = RMP ;
   VAM = 0.0 ;
   VNM = 0.0 ;
   VGA = 0.0 ;
   VGB = 0.0 ;
   VGBa = 0.0 ;
   offsetGB = 0.0 ;
   AHP = 0.0 ;
   rebob = - 1e9 ;
   invlt = - 1.0 ;
   t0 = t ;
   tGB = t ;
   tg = t ;
   twg = t ;
   trrs = t ;
   cbur = 0.0 ;
   spck = 0.0 ;
   refractory = 0.0 ;
   VTHC = VTH ;
   VTHR = VTH ;
    return 0; }
 
static double _hoc_reset(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 reset (  );
 return(_r);
}
 
/*VERBATIM*/
unsigned int GetDVIDSeedVal(unsigned int id) {
  double x[2];
  if (seadsetting==1) { 
    sead=((unsigned int)ip->id+seaddvioff)*1e6;
  } else { 
    if (seadsetting==2) printf("Warning: GetDVIDSeedVal called with wt rand turned off\n");
    x[0]=(double)id; x[1]=seaddvioff;
    sead=hashseed2(2,&x);
  }
  return sead;
}
 
double DVIDSeed (  ) {
   double _lDVIDSeed;
 
/*VERBATIM*/
  return (double)GetDVIDSeedVal(IDP->id);
 
return _lDVIDSeed;
 }
 
static double _hoc_DVIDSeed(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  DVIDSeed (  );
 return(_r);
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{    _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t;   if (_lflag == 1. ) {*(_tqitem) = 0;}
 {
   double _ltmp , _ljcn , _lid ;
 
/*VERBATIM*/
  int prty,poty,prin,ii,sy,nsyn; double STDf; //@

 tmax = t ;
   
/*VERBATIM*/
  if (stopoq && !qsz()) stoprun=1;
  ip=IDP; pg=ip->pg;
  if (ip->dead) return; // this cell has died
  _ljcn=ip->jcn; _lid=ip->id;
  tpnt = _pnt; // this pnt
  if (PATHMEASURE) { // do all code for this
    if (_lflag==2 || _lflag<0) { // on the callback -- distribute to divergence list
      double idty; int i;
      if (_lflag==2) ip->flag=-1; 
      idty=(double)(FOFFSET+ip->id)+1e-2*(double)ip->type+1e-3*(double)ip->inhib+1e-4;
      for (i=0;i<ip->dvt && !stoprun;i++) if (ip->sprob[i]) {
        (*pnt_receive[ip->dvi[i]->_prop->_type])(ip->dvi[i], wts, idty); 
        _p=_pnt->_prop->param; _ppvar=_pnt->_prop->dparam; ip=IDP; // restore pointers each time
      }
      return;  // else see if destination has been reached
    } else if (_lflag!=2 && (pathtytarg==(double)ip->type || pathidtarg==(double)ip->id)) {
      if (pathend==(double)ip->id) return; // means that coming back here again
      ip->flag=(unsigned char)floor(t)+1; // type-target or id-target
      pathend=(double)ip->id; 
      pathlen=tmax+1; // tmax gives pathlength
      stoprun=1.; 
      return;
      // deadends:visited || no output  ||stopped
    } else if (ip->flag   || ip->dvt==0 || stoprun) {
      return; // inhib cell is a deadend; don't revisit anyone
    } else if (ip->inhib) {
      if (!ip->flag) ip->flag=(unsigned char)floor(t)+1;
    } else { // first callback will be from the stim
      ip->flag=(unsigned char)floor(t)+1;
   #if defined(t)
      net_send((void**)0x0, wts,tpnt,t+1.,-1.); // the callback call
  #else
      net_send((void**)0x0, wts,tpnt,1.,-1.); // the callback call
  #endif
      return;
    }
  }
  if (_lflag==OK) { FLAG=OK; flag(); return; } // identify internal call with errflag
  if (_lflag<0) { callback(_lflag); return; }
  eventtot+=1;
 
/*VERBATIM*/
  if (ip->dbx>2) 
 {
     pid ( _threadargs_ ) ;
     printf ( "DB0: flag=%g Vm=%g" , _lflag , VAM + VNM + VGA + VGB + RMP + AHP ) ;
     if ( _lflag  == 0.0 ) {
       printf ( " (%g %g %g %g %g)" , _args[0] , _args[1] , _args[2] , _args[3] , _args[4] ) ;
       }
     printf ( "\n" ) ;
     }
   if ( _lflag >= FOFFSET ) {
     
/*VERBATIM*/
{
      // find type of presyn
      poty=(int)ip->type;
      prty=(int)(1e2*(_lflag-floor(_lflag)));
      prin=(int)(1e3*(_lflag-floor(_lflag)-prty*1e-2)); // stuffed into this flag
      sy=prin?GA:AM;
      STDf=_args[0]; // save value
      for (ii=0;ii<=4;ii++) _args[ii]=0.; // may be unnecessary to clear
      for (ii=sy,nsyn=0;ii<sy+2;ii++) nsyn+=((_args[ii]=WMAT(prty,poty,ii)*WD0(prty,poty,ii))>0.);
      if (nsyn==0) return;
      if (seadsetting!=2) { // not fixed weights
        if (seadsetting==1) {
          sead=(unsigned int)(floor(_lflag)*ip->id*seedstep); // all integers
        } else { // hash on presynaptic id+FOFFSET,poid,seedstep
          hsh[0]=floor(_lflag); hsh[1]=(double)ip->id; hsh[2]=seedstep;
          sead=hashseed2(3,&hsh); // hsh[] is just scratch pad
        }
        mcell_ran4(&sead, &_args[sy], 2, 1.);
        for (ii=sy;ii<sy+2;ii++) { // scale appropriately; 
          _args[ii]=2*WVAR*(_args[ii]+0.5/WVAR-0.5)*WMAT(prty,poty,ii)*WD0(prty,poty,ii);
        }
      }
    }
 
/*VERBATIM*/
    if (ip->dbx>2) 
 {
       pid ( _threadargs_ ) ;
       printf ( "DF: flag=%g Vm=%g" , _lflag , VAM + VNM + VGA + VGB + RMP + AHP ) ;
       printf ( " (%g %g %g %g %g)" , _args[0] , _args[1] , _args[2] , _args[3] , _args[4] ) ;
       printf ( "\n" ) ;
       }
     }
   else if ( _lflag  == 4.0 ) {
     cbur = cbur - 1.0 ;
     if ( cbur > 0.0 ) {
       artcell_net_send ( _tqitem, _args, _pnt, t +  tbur , 4.0 ) ;
       }
     else {
       refractory = 1.0 ;
       artcell_net_send ( _tqitem, _args, _pnt, t +  refrac , 3.0 ) ;
       }
     _ltmp = t ;
     
/*VERBATIM*/
    if (ip->jttr) 
 {
       _ltmp = t + jttr ( _threadargs_ ) / 10.0 ;
       }
     if ( _ljcn ) {
       jitcon ( _threadargscomma_ _ltmp ) ;
       }
     else {
       net_event ( _pnt, _ltmp ) ;
       }
     
/*VERBATIM*/
    spikes[ip->type]++; //@

 spck = spck + 1.0 ;
     
/*VERBATIM*/
    if (ip->dbx>0) 
 {
       pid ( _threadargs_ ) ;
       printf ( "DBA: mid-burst event at %g, %g\n" , _ltmp , cbur ) ;
       }
     
/*VERBATIM*/
    if (ip->record) 
 {
       recspk ( _threadargscomma_ _ltmp ) ;
       }
     
/*VERBATIM*/
    if (ip->wrec) 
 {
       wrecord ( _threadargscomma_ t ) ;
       }
     
/*VERBATIM*/
    return; //@ done

 }
   else if ( _lflag  == 0.0  && _args[3]  == 0.0  && _args[4]  == 1.0 ) {
     
/*VERBATIM*/
    ip->input=1; //@

 _args[4] = 2.0 ;
     randspk ( _threadargs_ ) ;
     artcell_net_send ( _tqitem, _args, _pnt, t +  nxt , 2.0 ) ;
     
/*VERBATIM*/
    return; //@ done

 }
   else if ( _lflag  == 0.0  && _args[3]  == 0.0  && _args[4]  == 2.0 ) {
     
/*VERBATIM*/
    ip->input=0; //@ inputs that are read from a vector of times -- see randspk()

 _args[4] = 1.0 ;
     
/*VERBATIM*/
    return; //@ done

 }
   
/*VERBATIM*/
  if (ip->record) 
 {
     record ( _threadargs_ ) ;
     }
   
/*VERBATIM*/
  if (ip->wrec) 
 {
     wrecord ( _threadargscomma_ 1e9 ) ;
     }
   if ( VAM > hoc_epsilon ) {
     VAM = VAM * EXP ( _threadargscomma_ - ( t - t0 ) / tauAM ) ;
     }
   else {
     VAM = 0.0 ;
     }
   if ( VNM > hoc_epsilon ) {
     VNM = VNM * EXP ( _threadargscomma_ - ( t - t0 ) / tauNM ) ;
     }
   else {
     VNM = 0.0 ;
     }
   if ( VGA < - hoc_epsilon ) {
     VGA = VGA * EXP ( _threadargscomma_ - ( t - t0 ) / tauGA ) ;
     }
   else {
     VGA = 0.0 ;
     }
   if ( refractory  == 0.0 ) {
     if ( VTHC > VTH ) {
       VTHC = VTH + ( VTHR - VTH ) * EXP ( _threadargscomma_ - ( t - trrs ) / tauRR ) ;
       }
     }
   if ( VGBdel > 0.0 ) {
     VGB = esinr ( _threadargscomma_ t - tGB ) ;
     }
   else {
     if ( VGB < - hoc_epsilon ) {
       VGB = VGB * EXP ( _threadargscomma_ - ( t - t0 ) / tauGB ) ;
       }
     else {
       VGB = 0.0 ;
       }
     }
   if ( AHP < - hoc_epsilon ) {
     AHP = AHP * EXP ( _threadargscomma_ - ( t - t0 ) / tauahp ) ;
     }
   else {
     AHP = 0.0 ;
     }
   t0 = t ;
   Vm = VAM + VNM + VGA + VGB + AHP ;
   if ( Vm > - RMP ) {
     Vm = - RMP ;
     }
   if ( Vm < RMP ) {
     Vm = RMP ;
     }
   if ( _lflag  == 0.0  || _lflag >= FOFFSET ) {
     if ( _args[0] > 0.0 ) {
       if ( rebob  != 1e9  && rebob  != - 1e9 ) {
         
/*VERBATIM*/
        cbur=floor(rebound*rebob/EGB); //@

 artcell_net_send ( _tqitem, _args, _pnt, t +  tbur , 4.0 ) ;
         rebob = 1e9 ;
         }
       if ( STDAM  == 0.0 ) {
         VAM = VAM + _args[0] * ( 1.0 - Vm / EAM ) ;
         }
       else {
         VAM = VAM + ( 1.0 - STDAM * STDf ) * _args[0] * ( 1.0 - Vm / EAM ) ;
         }
       if ( VAM > EAM ) {
         
/*VERBATIM*/
        AMo[ip->type]++; //@

 }
       else if ( VAM < 0.0 ) {
         VAM = 0.0 ;
         }
       }
     if ( _args[1] > 0.0  && VNM < ENM ) {
       rates ( _threadargscomma_ RMP + Vm ) ;
       if ( STDNM  == 0.0 ) {
         VNM = VNM + _args[1] * Bb * ( 1.0 - Vm / ENM ) ;
         }
       else {
         VNM = VNM + ( 1.0 - STDNM * STDf ) * _args[1] * Bb * ( 1.0 - Vm / ENM ) ;
         }
       if ( VNM > ENM ) {
         
/*VERBATIM*/
        NMo[ip->type]++; //@

 }
       else if ( VNM < 0.0 ) {
         VNM = 0.0 ;
         }
       }
     if ( _args[2] > 0.0  && VGA > EGA ) {
       if ( STDGA  == 0.0 ) {
         VGA = VGA - _args[2] * ( 1.0 - Vm / EGA ) ;
         }
       else {
         VGA = VGA - ( 1.0 - STDGA * STDf ) * _args[2] * ( 1.0 - Vm / EGA ) ;
         }
       if ( VGA < EGA ) {
         
/*VERBATIM*/
        GAo[ip->type]++; //@

 
/*VERBATIM*/
  if (ip->dbx>2) 
 {
           pid ( _threadargs_ ) ;
           printf ( "DB0A: flag=%g Vm=%g" , _lflag , VAM + VNM + VGA + VGB + RMP + AHP ) ;
           if ( _lflag  == 0.0 ) {
             printf ( " (%g %g %g %g %g %g)" , _args[2] , EGA , VGA , Vm , AHP , STDf ) ;
             }
           
/*VERBATIM*/
    printf("\nAA:%d:%d\n",GAo[ip->type],ip->type); //@ 

 printf ( "\n" ) ;
           }
         }
       else if ( VGA > 0.0 ) {
         VGA = 0.0 ;
         }
       }
     if ( _args[3] > 1e-6 ) {
       if ( VGBdel > 0.0 ) {
         artcell_net_send ( _tqitem, _args, _pnt, t +  VGBdel , 5.0 ) ;
         }
       else {
         _args[4] = _args[4] * EXP ( _threadargscomma_ - ( t - tGB ) / tauGBGP ) + wGBGP ;
         coop ( _threadargscomma_ _args[4] ) ;
         VGB = VGB - _args[3] * ( 1.0 - Vm / EGB ) * Gn ;
         if ( VGB < EGB ) {
           
/*VERBATIM*/
          GBo[ip->type]++; //@

 }
         if ( VGB < rebob  && rebob  != 1e9  && rebob  != - 1e9 ) {
           rebob = VGB ;
           }
         }
       }
     
/*VERBATIM*/
    if (ip->invl0) 
 {
       Vm = RMP + VAM + VNM + VGA + VGB + AHP ;
       if ( Vm > 0.0 ) {
         Vm = 0.0 ;
         }
       if ( Vm < - 90.0 ) {
         Vm = - 90.0 ;
         }
       if ( invlt  == - 1.0 ) {
         if ( Vm > RMP ) {
           oinvl = invl ;
           invlt = t ;
           artcell_net_send ( _tqitem, _args, _pnt, t +  invl , 1.0 ) ;
           }
         }
       else {
         _ltmp = shift ( _threadargscomma_ Vm ) ;
         if ( _ltmp  != 0.0 ) {
           artcell_net_move ( _tqitem, _pnt, _ltmp ) ;
           if ( id ( _threadargs_ ) < prnum ) {
             pid ( _threadargs_ ) ;
             printf ( "**** MOVE t=%g to %g Vm=%g %g,%g\n" , t , _ltmp , Vm , invlt , oinvl ) ;
             }
           }
         }
       }
     }
   else if ( _lflag  == 1.0 ) {
     if ( WINV < 0.0 ) {
       if ( _ljcn ) {
         jitcon ( _threadargscomma_ t ) ;
         }
       else {
         net_event ( _pnt, t ) ;
         }
       
/*VERBATIM*/
      spikes[ip->type]++; //@

 spck = spck + 1.0 ;
       
/*VERBATIM*/
      if (ip->dbx>0) 
 {
         pid ( _threadargs_ ) ;
         printf ( "DBC: interval event\n" ) ;
         }
       
/*VERBATIM*/
      if (ip->record) 
 {
         recspk ( _threadargscomma_ t ) ;
         }
       
/*VERBATIM*/
      if (ip->wrec) 
 {
         wrecord ( _threadargscomma_ t ) ;
         }
       }
     else {
       _ltmp = WINV * ( 1.0 - Vm / EAM ) ;
       VAM = VAM + _ltmp ;
       }
     oinvl = invl ;
     invlt = t ;
     artcell_net_send ( _tqitem, _args, _pnt, t +  invl , 1.0 ) ;
     }
   else if ( _lflag  == 5.0 ) {
     offsetGB = VGB ;
     _args[4] = _args[4] * EXP ( _threadargscomma_ - ( t - tGB ) / tauGBGP ) + wGBGP ;
     coop ( _threadargscomma_ _args[4] ) ;
     if ( VGB > EGB ) {
       _ltmp = _args[3] * ( 1.0 - Vm / EGB ) * Gn ;
       VGB = VGB - _ltmp ;
       }
     VGBa = VGB ;
     tGB = t ;
     }
   else if ( _lflag  == 2.0 ) {
     if ( _lflag  == 2.0 ) {
       
/*VERBATIM*/
      if (ip->dbx>1) 
 {
         pid ( _threadargs_ ) ;
         printf ( "DBBa: randspk called: %g,%g\n" , WEX , nxt ) ;
         }
       if ( WEX < 0.0 ) {
         if ( _ljcn ) {
           jitcon ( _threadargscomma_ t ) ;
           }
         else {
           net_event ( _pnt, t ) ;
           }
         
/*VERBATIM*/
        spikes[ip->type]++; //@

 spck = spck + 1.0 ;
         
/*VERBATIM*/
        if (ip->dbx>0) 
 {
           pid ( _threadargs_ ) ;
           printf ( "DBB: randspk event\n" ) ;
           }
         if ( WEX < - 1.0  && WEX  != - 1e9 ) {
           cbur = - WEX ;
           artcell_net_send ( _tqitem, _args, _pnt, t +  tbur , 4.0 ) ;
           }
         
/*VERBATIM*/
        if (ip->record) 
 {
           recspk ( _threadargscomma_ t ) ;
           }
         
/*VERBATIM*/
        if (ip->wrec) 
 {
           wrecord ( _threadargscomma_ t ) ;
           }
         }
       else if ( WEX > 0.0 ) {
         _ltmp = WEX * ( 1.0 - Vm / EAM ) ;
         VAM = VAM + _ltmp ;
         }
       if ( WEX  != - 1e9 ) {
         randspk ( _threadargs_ ) ;
         if ( nxt > 0.0 ) {
           artcell_net_send ( _tqitem, _args, _pnt, t +  nxt , 2.0 ) ;
           }
         }
       }
     }
   else if ( _lflag  == 3.0 ) {
     refractory = 0.0 ;
     trrs = t ;
     
/*VERBATIM*/
    return; //@ done

 }
   Vm = VAM + VNM + VGA + VGB + RMP + AHP ;
   if ( Vm > 0.0 ) {
     Vm = 0.0 ;
     }
   if ( Vm < - 90.0 ) {
     Vm = - 90.0 ;
     }
   if ( refractory  == 0.0  && Vm > VTHC ) {
     
/*VERBATIM*/
    if (!ip->vbr && Vm>Vblock) {//@ do nothing

 
/*VERBATIM*/
      ip->blkcnt++; blockcnt[ip->type]++; return; }//@

 AHP = AHP - ahpwt ;
     _ltmp = t ;
     
/*VERBATIM*/
    if (ip->jttr) 
 {
       _ltmp = t + jttr ( _threadargs_ ) ;
       }
     if ( _ljcn ) {
       jitcon ( _threadargscomma_ _ltmp ) ;
       }
     else {
       net_event ( _pnt, _ltmp ) ;
       }
     
/*VERBATIM*/
    spikes[ip->type]++; //@

 spck = spck + 1.0 ;
     
/*VERBATIM*/
    if (ip->dbx>0) 
 {
       pid ( _threadargs_ ) ;
       printf ( "DBD: %g>VTH(%g) event at %g (STDf=%g)\n" , Vm , VTHC , _ltmp , STDf ) ;
       }
     
/*VERBATIM*/
    if (ip->record) 
 {
       recspk ( _threadargscomma_ _ltmp ) ;
       }
     
/*VERBATIM*/
    if (ip->wrec) 
 {
       wrecord ( _threadargscomma_ _ltmp ) ;
       }
     VTHC = VTH + RRWght * ( Vblock - VTH ) ;
     VTHR = VTHC ;
     refractory = 1.0 ;
     if ( nbur > 1.0 ) {
       cbur = nbur - 1.0 ;
       artcell_net_send ( _tqitem, _args, _pnt, t +  tbur , 4.0 ) ;
       
/*VERBATIM*/
      return; //@ done

 }
     else if ( rebob  == 1e9 ) {
       rebob = 0.0 ;
       }
     
/*VERBATIM*/
    if (ip->vbr && Vm>Vblock) 
 {
       artcell_net_send ( _tqitem, _args, _pnt, t +  Vbrefrac , 3.0 ) ;
       
/*VERBATIM*/
      if (ip->dbx>0) 
 {
         pid ( _threadargs_ ) ;
         printf ( "DBE: %g %g\n" , Vbrefrac , Vm ) ;
         }
       
/*VERBATIM*/
      return; //@ done

 }
     artcell_net_send ( _tqitem, _args, _pnt, t +  refrac , 3.0 ) ;
     }
   } }
 
static void _net_init(Point_process* _pnt, double* _args, double _lflag) {
    _args[1] = _args[1] ;
   _args[2] = _args[2] ;
   _args[3] = _args[3] ;
   _args[4] = 0.0 ;
   }
 
static int  jitcon (  double _ltm ) {
   
/*VERBATIM*/
{
  double mindel, randel, idty, *x; int prty, poty, i, j, k, dv; 
  Point_process *pnt; void* voi;
  // qsz = nrn_event_queue_stats(stt);
  // if (qsz>=qlimit) { printf("qlimit %g exceeded at t=%g\n",qlimit,t); qlimit*=2; }
  ip=IDP;
  if (!pg) {printf("No network defined -- must run jitcondiv() and pgset\n"); hxe();}
  ip->spkcnt++; // jitcon() called from NET_RECEIVE which sets ip
  if (jrj<jrmax) { 
    jrid[jrj]=(double)ip->id; jrtv[jrj]=_ltm;
    jrj++;
  } else if (wf2 && jrmax) spkoutf2(); // saving spike times
  jri++;  // keep track of number of spikes
  if (jrtm>0) {
    if (t>jrtime) {
      jrtime+=jrtm;
      spkstats2(1.);
    }
  } else if (jrsvd>0 && jri>jrsvn) { 
    jrsvn+=jrsvd; printf("t=%.02f %ld ",t,jri);
    spkstats2(1.);
  }
  prty=(int)ip->type;
  if (ip->jcn==1) if (ip->dvt>0) {  // first callback
      #if defined(t)
    if (ip->jcn==1) if (ip->dvt>0) net_send((void**)0x0, wts,tpnt,t+ip->del[0],-1.);
      #else
    if (ip->jcn==1) if (ip->dvt>0) net_send((void**)0x0, wts,tpnt,ip->del[0],-1.);
      #endif
  }
  }   
  return 0; }
 
static double _hoc_jitcon(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 jitcon (  *getarg(1) );
 return(_r);
}
 
static int  spkstats (  ) {
   
/*VERBATIM*/
{
  if (ifarg(1)) tf=hoc_obj_file_arg(1); else tf=0x0;
}
  return 0; }
 
static double _hoc_spkstats(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 spkstats (  );
 return(_r);
}
 
static int  spkoutf (  ) {
   
/*VERBATIM*/
{
  if (ifarg(2)) {
    wf1=hoc_obj_file_arg(1); // index file
    wf2=hoc_obj_file_arg(2);
  } else if (wf1 != 0x0) {
    spkoutf2();
    wf1=(FILE*)0x0; wf2=(FILE*)0x0;
  }
}
  return 0; }
 
static double _hoc_spkoutf(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 spkoutf (  );
 return(_r);
}
 
/*VERBATIM*/
static int spkoutf2 () {
    fprintf(wf1,"//b9 -2 t%0.2f %ld %ld\n",t/1e3,jrj,ftell(wf2));
    fwrite(jrtv,sizeof(double),jrj,wf2); // write times
    fwrite(jrid,sizeof(double),jrj,wf2); // write id
    fflush(wf1); fflush(wf2);
    jrj=0;
}
 
static int  callhoc (  ) {
   
/*VERBATIM*/
  if (ifarg(1)) {
    cbsv=hoc_lookup(gargstr(1));
  } else {
    cbsv=0x0;
  }
  return 0; }
 
static double _hoc_callhoc(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 callhoc (  );
 return(_r);
}
 
static int  spkstats2 (  double _lflag ) {
   
/*VERBATIM*/
{
  int i, ix, flag; double clk;
  flag=(int)(_lflag+1e-6);
  clk=clock()-savclock; savclock=clock();
  if (cbsv) hoc_call_func(cbsv,0);
  if (tf) fprintf(tf,"t=%.02f;%ld(%g) ",t,jri,clk/1e6); else {
    printf("t=%.02f;%ld(%g) ",t,jri,clk/1e6); }
  for (i=0;i<CTYN;i++) {
    ix=cty[i];
    spktot+=spikes[ix];
    if (tf) {
      fprintf(tf,"%s:%d/%d:%d;%d;%d;%d ",CNAME[i],spikes[ix],\
              blockcnt[ix],AMo[ix],NMo[ix],GAo[ix],GBo[ix]);
    } else {
      printf("%s:%d/%d:%d;%d;%d;%d ",CNAME[i],spikes[ix],blockcnt[ix],\
             AMo[ix],NMo[ix],GAo[ix],GBo[ix]);
    }
    spck=0;
    blockcnt[ix]=spikes[ix]=0;
    AMo[ix]=NMo[ix]=GAo[ix]=GBo[ix]=0;
  }
  if (tf && flag==2) {  fprintf(tf,"\nt=%g tot_spks: %ld; tot_events: %ld\n",t,spktot,eventtot); 
  } else if (flag==2) {  printf("\ntotal spikes: %ld; total events: %ld\n",spktot,eventtot); 
  } else if (tf) fprintf(tf,"\n"); else printf("\n");
}
  return 0; }
 
static double _hoc_spkstats2(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 spkstats2 (  *getarg(1) );
 return(_r);
}
 
static int  oobpr (  ) {
   
/*VERBATIM*/
{
  int i,ix;
  for (i=0;i<CTYN;i++){ 
    ix=cty[i];
    printf("%d:%d/%d:%d;%d;%d;%d ",ix,spikes[ix],blockcnt[ix],AMo[ix],NMo[ix],GAo[ix],GBo[ix]);
  }
  printf("\n");
}
  return 0; }
 
static double _hoc_oobpr(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 oobpr (  );
 return(_r);
}
 
static int  callback (  double _lfl ) {
   
/*VERBATIM*/
{
  int i; double idty, del0, ddel; id0 *jp; Point_process *upnt; // these must be local
  i=(unsigned int)((-_lfl)-1); // -1,-2,-3 -> 0,1,2
  jp=IDP; upnt=tpnt; del0=jp->del[i]; ddel=0.;
  idty=(double)(FOFFSET+jp->id)+1e-2*(double)jp->type+1e-3*(double)jp->inhib+1e-4;
  while (ddel<=DELMIN) { // check if this del is worth waiting, else just send now
    if (Vblock<VTHC) { 
      wts[0]=0; // send [0,1] for STD
    } else { // STDf=(1-STD)
      wts[0]=(VTHC-VTH)/(Vblock-VTH); // just send [0,1] for STD
    }
    if (jp->sprob[i]) (*pnt_receive[jp->dvi[i]->_prop->_type])(jp->dvi[i], wts, idty); 
    _p=upnt->_prop->param; _ppvar=upnt->_prop->dparam; // restore pointers
    i++;
    if (i>=jp->dvt) return; // ran out
    ddel=jp->del[i]-del0;   // delays are relative to event; use difference in delays
  }
  // skip over pruned outputs and dead cells:
  while (i<jp->dvt && (!jp->sprob[i] || (*(id0**)&(jp->dvi[i]->_prop->dparam[2]))->dead)) i++;
  if (i<jp->dvt) {
    ddel= jp->del[i] - del0;;
  #if defined(t)
    net_send((void**)0x0, wts,upnt,t+ddel,(double) -(i+1)); // next callback
  #else
    net_send((void**)0x0, wts,upnt,ddel,(double) -(i+1)); // next callback
  #endif
  }
  } 
  return 0; }
 
static double _hoc_callback(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 callback (  *getarg(1) );
 return(_r);
}
 
static int  mkdvi (  ) {
   
/*VERBATIM*/
{
  int i,j,k,prty,poty,dv,dvt,dvii; double *x, *db, *dbs; 
  Object *lb;  Point_process *pnnt, **da, **das;
  ip=IDP; pg=ip->pg; // this should be called right after jitcondiv()
  if (ip->dead) return;
  prty=ip->type;
  sead=GetDVIDSeedVal(ip->id);//seed for divergence and delays
  for (i=0,k=0,dvt=0;i<CTYN;i++) { // dvt gives total divergence
    poty=cty[i];
    dvt+=DVG(prty,poty);
  }
  da =(Point_process **)malloc(dvt*sizeof(Point_process *));
  das=(Point_process **)malloc(dvt*sizeof(Point_process *)); // das,dbs for after sort
  db =(double *)malloc(dvt*sizeof(double)); // delays
  dbs=(double *)malloc(dvt*sizeof(double)); // delays
  for (i=0,k=0,dvii=0;i<CTYN;i++) { // cell types in cty[]
    poty=cty[i];
    dv=DVG(prty,poty);
    if (dv>0) {
      sead+=dv;
      if (dv>dscrsz) {
        printf("B:Divergence exceeds dscrsz: %d>%d for %d->%d\n",dv,dscrsz,prty,poty); hxe(); }
      mcell_ran4(&sead, dscr ,  dv, pg->ixe[poty]-pg->ix[poty]+1);
      for (j=0;j<dv;j++) {
        if (!(lb=ivoc_list_item(ce,(unsigned int)floor(dscr[j]+pg->ix[poty])))) {
          printf("INTF:callback %g exceeds %d for list ce\n",floor(dscr[j]+pg->ix[poty]),cesz); 
          hxe(); }
        pnnt=(Point_process *)lb->u.this_pointer;
        da[j+dvii]=pnnt;
      }
      mcell_ran4(&sead, dscr , dv, 2*DELD(prty,poty));
      for (j=0;j<dv;j++) {
        db[j+dvii]=dscr[j]+DELM(prty,poty)-DELD(prty,poty); // +/- DELD
        if (db[j+dvii]<0) db[j+dvii]=-db[j+dvii];
      }
      dvii+=dv;
    }
  }
  gsort2(db,da,dvt,dbs,das);
  ip->del=dbs;   ip->dvi=das;   ip->dvt=dvt;
  ip->sprob=(unsigned char *)malloc(dvt*sizeof(char *)); // release probability
  for (i=0;i<dvt;i++) ip->sprob[i]=1; // start out with all firing
  free(da); free(db); // keep das,dbs which are assigned to ip->dvi bzw ip->del
  }
  return 0; }
 
static double _hoc_mkdvi(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 mkdvi (  );
 return(_r);
}
 
static int  patha2b (  ) {
   
/*VERBATIM*/
  int i; double idty, *x; static Point_process *_pnt; static id0 *ip0;
  pathbeg=*getarg(1); pathidtarg=*getarg(2);
  pathtytarg=-1;  PATHMEASURE=1; pathlen=stopoq=0;
  for (i=0;i<cesz;i++) { lop(ce,i); 
    if ((i==pathbeg || i==pathidtarg) && qp->inhib) {
      pid(); printf("Checking to or from inhib cell\n" ); hxe(); }
    qp->flag=qp->vinflg=0; 
  }
  hoc_call_func(hoc_lookup("finitialize"), 0);
  cvode_fadvance(1000.0); // this call will not return
  return 0; }
 
static double _hoc_patha2b(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 patha2b (  );
 return(_r);
}
 
double pathgrps (  ) {
   double _lpathgrps;
 
/*VERBATIM*/
  int i,j,k,na,nb,flag; double idty,*a,*b,*x,sum; static Point_process *_pnt; static id0 *ip0;
  Symbol* s; char **pfl;
  x=0x0;
  s=hoc_lookup("finitialize");
  if (ifarg(2)) {
    na=vector_arg_px(1,&a);
    nb=vector_arg_px(2,&b);
    if (ifarg(3)) x=vector_newsize(vector_arg(3),na*nb);
  } else {
    na=nb=cesz;  // may want to put output into an unsigned char eventually
    if (ifarg(1)) x=vector_newsize(vector_arg(1),na*nb);
  }
  // if (scrsz<cesz) scrset(cesz); 
  pfl = (char **)malloc(cesz * (unsigned)sizeof(char *));
  for (i=0;i<cesz;i++) { lop(ce,i); scr[i]=qp->inhib; pfl[i]=&qp->flag; }
  pathtytarg=-1;  PATHMEASURE=1; pathlen=stopoq=0;
  for (k=0,sum=0;k<na;k++) {
    pathbeg=a[k]; 
    if (scr[(int)pathbeg]) { 
      if (x) for (j=0;j<nb;j++) x[k*nb+j]=0.;
      continue;
    }
    for (j=0;j<nb;j++) { 
      pathidtarg=b[j]; 
      if (scr[(int)pathidtarg]) { if (x) x[k*nb+j]=0.; 
        continue;
      }
      // for (i=0;i<cesz;i++) {lop(ce,i); qp->flag=0;}
      for (i=0;i<cesz;i++) *pfl[i]=0;
      hoc_call_func(s, 0);
      cvode_fadvance(1000.0); // this call will not return
      sum+=pathlen;
      if (x) x[k*nb+j]=pathlen;
    }
  }
  PATHMEASURE=0;
  free(pfl);
  _lpathgrps=sum/na/nb;
 
return _lpathgrps;
 }
 
static double _hoc_pathgrps(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  pathgrps (  );
 return(_r);
}
 
double getdvi (  ) {
   double _lgetdvi;
 
/*VERBATIM*/

  {
    int i,j,k,iarg,av1,a2,a3,a4,dvt,getactive=0,idx=0,*pact,prty,poty,sy,ii; 
    double *dbs, *x,*x1,*x2,*x3,*x4,*x5,idty,y[2],flag;
    void* voi, *voi2,*voi3; Point_process **das;
    ip=IDP; pg=ip->pg; // this should be called right after jitcondiv()
    getactive=a2=a3=a4=0;
    if (ip->dead) return;
    dvt=ip->dvt;
    dbs=ip->del;   das=ip->dvi;
    _lgetdvi=(double)dvt; 
    if (!ifarg(1)) return _lgetdvi; // just return the divergence value
    iarg=1;
    if (hoc_is_double_arg(iarg)) {
      av1=2;
      flag=*getarg(iarg++);
      getactive=(int)flag;
      flag-=(double)getactive; // flag is in the decimal place 1.2 has flag of 2
      if (flag!=0) flag=floor(flag*10+hoc_epsilon); // avoid roundoff error
    } else av1=1; // 1st vector arg
    //just get active postsynapses (not dead and non pruned)
    voi=vector_arg(iarg++); 
    if (flag==2) { x1=vector_newsize(voi,CTYPi); for (i=0;i<CTYPi;i++) x1[i]=0;
    } else x1=vector_newsize(voi,dvt);
    if (ifarg(iarg)) { voi=vector_arg(iarg++); x2=vector_newsize(voi,dvt);  a2=1; }
    if (ifarg(iarg)) { voi=vector_arg(iarg++); x3=vector_newsize(voi,dvt); a3=1;}
    if (ifarg(iarg)) { // need 2 weight vecs for AM/NM or GA/GB
      voi=vector_arg(iarg++); x4=vector_newsize(voi,dvt); a4=1;
      voi=vector_arg(iarg++); x5=vector_newsize(voi,dvt);
    }
    idty=(double)(FOFFSET+ip->id)+1e-2*(double)ip->type+1e-3*(double)ip->inhib+1e-4;
    prty=ip->type; sy=ip->inhib?GA:AM;
    for (i=0,j=0;i<dvt;i++) {
      qp=*((id0**) &((das[i]->_prop->dparam)[2])); // #define sop	*_ppvar[2].pval
      if (getactive && (qp->dead || ip->sprob[i]==0)) continue;
      if (flag==1) { x1[j]=(double)qp->type; 
      } else if (flag==2) { x1[qp->type]++; 
      } else if (flag==3) { x1[j]=(double)qp->col; 
      } else x1[j]=(double)qp->id;
      if (a2) x2[j]=dbs[i];
      if (a3) x3[j]=(double)ip->sprob[i];
      if (a4) {
        poty = qp->type;
        if (seadsetting==2) { // no randomization
          for(ii=0;ii<2;ii++) y[ii]=WMAT(prty,poty,sy+ii)*WD0(prty,poty,sy+ii);
        } else {
          if (seadsetting==1) { // old sead setting
            sead=(unsigned int)(FOFFSET+ip->id)*qp->id*seedstep; 
          } else { // hashed sead setting
            hsh[0]=(double)(FOFFSET+ip->id); hsh[1]=(double)(qp->id); hsh[2]=seedstep;
            sead=hashseed2(3,&hsh); 
          }
          mcell_ran4(&sead, y, 2, 1.);
          for(ii=0;ii<2;ii++) {
            y[ii]=2*WVAR*(y[ii]+0.5/WVAR-0.5)*WMAT(prty,poty,sy+ii)*WD0(prty,poty,sy+ii); }
        }
        x4[j]=y[0]; x5[j]=y[1];
      }
      j++;
    }
    if (flag!=2 && j!=dvt) for (i=av1;i<iarg;i++) vector_resize(vector_arg(i),j);
    _lgetdvi=(double)j; 
  }
 
return _lgetdvi;
 }
 
static double _hoc_getdvi(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  getdvi (  );
 return(_r);
}
 
double getconv (  ) {
   double _lgetconv;
 
/*VERBATIM*/

{
  int iarg,i,j,k,dvt,sz,prfl,getactive; double *x,flag;
  void* voi; Point_process **das; id0 *pp;
  ip=IDP; pg=ip->pg; // this should be called right after jitcondiv()
  sz=ip->dvt; //  // assume conv similar to div
  getactive=0;
  if (ifarg(iarg=1) && hoc_is_double_arg(iarg)) {
    flag=*getarg(iarg++);
    getactive=(int)flag;
    flag-=(double)getactive; // flag is in the decimal place 1.2 has flag of 2
    if (flag!=0) flag=floor(flag*10+hoc_epsilon);
  }
  if (!ifarg(iarg)) prfl=0; else { prfl=1;
    voi=vector_arg(iarg); 
    if (flag==2.) { x=vector_newsize(voi,CTYPi); for (i=0;i<CTYPi;i++) x[i]=0;
    } else x=vector_newsize(voi,sz); 
  } 
  for (i=0,k=0; i<cesz; i++) {
    lop(ce,i);
    if (getactive && qp->dead) continue;
    dvt=qp->dvt; das=qp->dvi;
    for (j=0;j<dvt;j++) {
      if (getactive && qp->sprob[j]==0) continue;
      if (ip==*((id0**) &((das[j]->_prop->dparam)[2]))) {
        if (prfl) {
          if (flag!=2.0 && k>=sz) x=vector_newsize(voi,sz*=2);
          if (flag==1.0) { x[k]=(double)qp->type; 
          } else if (flag==2.0) { x[qp->type]++; 
          } else x[k]=(double)qp->id;
        } 
        k++;
        break;
      }
    }
  }
  if (prfl && flag!=2) vector_resize(voi,k);
  _lgetconv=(double)k;
}
 
return _lgetconv;
 }
 
static double _hoc_getconv(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  getconv (  );
 return(_r);
}
 
double adjlist (  ) {
   double _ladjlist;
 
/*VERBATIM*/
  Object* pList = *hoc_objgetarg(1);
  int iListSz=ivoc_list_count(pList),iCell,iStartID=ifarg(2)?*getarg(2):0,\
    iEndID=ifarg(3)?*getarg(3):cesz-1;
  int skipinhib = ifarg(4)?*getarg(4):0, i,j,nv,*pused=(int*)calloc(cesz,sizeof(int)),iSyns=0;
  double **vvo = (double**)malloc(sizeof(double*)*iListSz),\
    *psyns=(double*)calloc(cesz,sizeof(double));
  id0* rp;
  for(iCell=iStartID;iCell<=iEndID;iCell++){
    if(verbose && iCell%1000==0) printf("%d ",iCell);
    lop(ce,iCell);
    if(!qp->dvt || (skipinhib && qp->inhib)){
      list_vector_resize(pList,iCell,0);
      continue;
    }
    iSyns=0;
    for(j=0;j<qp->dvt;j++){      
      rp=*((id0**) &((qp->dvi[j]->_prop->dparam)[2])); // #define sop	*_ppvar[2].pval      
      if(skipinhib && rp->inhib) continue; // if skip inhib cells...
      if(!rp->dead && qp->sprob[j]>0. && !pused[rp->id]){      
        pused[rp->id]=1;
        psyns[iSyns++]=rp->id;
      }
    }
    list_vector_resize(pList, iCell, iSyns);
    list_vector_px(pList, iCell, &vvo[iCell]);
    memcpy(vvo[iCell],psyns,sizeof(double)*iSyns);
    for(j=0;j<iSyns;j++)pused[(int)psyns[j]]=0;
  }
  free(vvo);  free(pused);  free(psyns);
  if (verbose) printf("\n");
  return 1.0;
 
return _ladjlist;
 }
 
static double _hoc_adjlist(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  adjlist (  );
 return(_r);
}
 
double rddvi (  ) {
   double _lrddvi;
 
/*VERBATIM*/
  Point_process *pnnt;
  FILE* fp;
  int i, iCell;
  unsigned int iOutID;
  Object* lb;
  fp=hoc_obj_file_arg(1);
  printf("reading: ");
  for(iCell=0;iCell<cesz;iCell++){
    if(iCell%1000==0)printf("%d ",iCell);
    lop(ce,iCell);
    fread(&qp->id,sizeof(unsigned int),1,fp); // read id
    fread(&qp->type,sizeof(unsigned char),1,fp); // read type id
    fread(&qp->col,sizeof(unsigned int),1,fp); // read column id
    fread(&qp->dead,sizeof(unsigned char),1,fp); // read alive/dead status
    fread(&qp->dvt,sizeof(unsigned int),1,fp); // read divergence size
    //free up old pointers
    if(qp->del){ free(qp->del); free(qp->dvi); free(qp->sprob);
      qp->dvt=0; qp->dvi=(Point_process**)0x0; qp->del=(double*)0x0; qp->sprob=(char *)0x0; }
    //if divergence == 0 , continue
    if(!qp->dvt) continue;
    qp->dvi = (Point_process**)malloc(sizeof(Point_process*)*qp->dvt);  
    for(i=0;i<qp->dvt;i++){
      fread(&iOutID,sizeof(unsigned int),1,fp); // id of output cell
      if (!(lb=ivoc_list_item(ce,iOutID))) {
        printf("INTF:callback %d exceeds %d for list ce\n",iOutID,cesz); hxe(); }
      qp->dvi[i]=(Point_process *)lb->u.this_pointer;
    }
    qp->del = (double*)malloc(sizeof(double)*qp->dvt);
    fread(qp->del,sizeof(double),qp->dvt,fp); // read divergence delays
    qp->sprob = (unsigned char*)malloc(sizeof(unsigned char)*qp->dvt);
    fread(qp->sprob,sizeof(unsigned char),qp->dvt,fp); // read divergence firing probabilities
  }
  printf("\n");
  return 1.0;
 
return _lrddvi;
 }
 
static double _hoc_rddvi(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  rddvi (  );
 return(_r);
}
 
double svdvi (  ) {
   double _lsvdvi;
 
/*VERBATIM*/
  Point_process *pnnt;
  FILE* fp;
  int i , iCell;
  fp=hoc_obj_file_arg(1);
  printf("writing: ");
  for(iCell=0;iCell<cesz;iCell++){
    if(iCell%1000==0)printf("%d ",iCell);
    lop(ce,iCell);
    fwrite(&qp->id,sizeof(unsigned int),1,fp); // write id
    fwrite(&qp->type,sizeof(unsigned char),1,fp); // write type id
    fwrite(&qp->col,sizeof(unsigned int),1,fp); // write column id
    fwrite(&qp->dead,sizeof(unsigned char),1,fp); // write alive/dead status
    fwrite(&qp->dvt,sizeof(unsigned int),1,fp); // write divergence size
    if(!qp->dvt)continue; //don't write empty pointers if no divergence
    for(i=0;i<qp->dvt;i++){
      pnnt=qp->dvi[i];
      fwrite(&(*(id0**)&(pnnt->_prop->dparam[2]))->id,sizeof(unsigned int),1,fp); // id of output cell
    }
    fwrite(qp->del,sizeof(double),qp->dvt,fp); // write divergence delays
    fwrite(qp->sprob,sizeof(unsigned char),qp->dvt,fp); // write divergence firing probabilities
  }
  printf("\n"); 
  return 1.0;
 
return _lsvdvi;
 }
 
static double _hoc_svdvi(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  svdvi (  );
 return(_r);
}
 
double setdvir (  ) {
   double _lsetdvir;
 
/*VERBATIM*/
  ListVec* pListWires,*pListDels;
  int i,dn,flag,dvt,idvfl,iCell,iStartID,iEndID,nidv,end; 
  double *y, *d, *idvec; unsigned char pdead;
  pListWires = AllocListVec(*hoc_objgetarg(1));
  idvfl=flag=0; iStartID=0; iEndID=cesz-1;
  if(!pListWires){printf("setalldvi ERRA: problem initializing wires list arg!\n"); hxe();}
  pListDels = AllocListVec(*hoc_objgetarg(2));
  if(!pListDels){ printf("setalldvi ERRA: problem initializing delays list arg!\n");
    FreeListVec(&pListWires); hxe(); }
  if (ifarg(3) && !ifarg(4)) { 
    flag=(int)*getarg(3); 
  } else if (hoc_is_double_arg(3)) {
    iStartID=(int)*getarg(3);
    iEndID = (int)*getarg(4);
    if(ifarg(5)) flag=(int)*getarg(5);
  } else {
    nidv=vector_arg_px(3, &idvec);
    idvfl=1;
    if (ifarg(4)) flag=(int)*getarg(4);
  }
  end=idvfl?nidv:(iEndID-iStartID+1);
  for (i=0;i<end;i++) {
    if(i%1000==0) printf("%d",i/1000);
    iCell=idvfl?idvec[i]:(iStartID+i);
    lop(ce,iCell);
    if (qp->dead) continue;
    y=pListWires->pv[i]; dvt=pListWires->plen[i];
    if(!dvt) continue; //skip empty div lists
    d=pListDels->pv[i];  dn=pListDels->plen[i];
    if (dn!=dvt) {printf("setdvir() ERR vec sizes for wire,delay list entries not equal %d: %d %d\n",i,dvt,dn); hxe();}
    setdvi2(y,d,dvt,flag);
  }
  FreeListVec(&pListWires);
  FreeListVec(&pListDels);
  return 1.0;
 
return _lsetdvir;
 }
 
static double _hoc_setdvir(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  setdvir (  );
 return(_r);
}
 
static int  clrdvi (  ) {
   
/*VERBATIM*/
  int i;
  for (i=0;i<cesz;i++) { 
    lop(ce,i);
    if (qp->dvt!=0x0) {
      free(qp->dvi); free(qp->del); free(qp->sprob);
      qp->dvt=0; qp->dvi=(Point_process**)0x0; qp->del=(double*)0x0; qp->sprob=(char *)0x0;
    }
  }
  return 0; }
 
static double _hoc_clrdvi(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 clrdvi (  );
 return(_r);
}
 
double setdviv (  ) {
   double _lsetdviv;
 
/*VERBATIM*/
  int i,j,k,nprv,dvt; double *prv,*pov,*dlv,x;
  nprv=vector_arg_px(1, &prv);
  i=vector_arg_px(2, &pov);
  j=vector_arg_px(3, &dlv);
  if (nprv!=i || i!=j) {printf("intf:setdviv ERRA: %d %d %d\n",nprv,i,j); hxe();}
  // start by counting the prids so will know the size that we need for realloc()
  if (scrsz<cesz) scrset(cesz); 
  for (i=0;i<cesz;i++) scr[i]=0;
  for (i=0,j=-1;i<nprv;i++) {
    if (j>(int)prv[i]){printf("intf:setdviv ERRA vecs should be sorted by prid vec\n");hxe();}
    j=(int)prv[i];
    scr[j]++;
  }
  for (i=0,x=-1,k=0;i<nprv;i+=dvt) { if(i%1000==0) printf(".");
    if (prv[i]!=x) lop(ce,(unsigned int)(x=prv[i]));
    if (qp->dead) continue;
    dvt=scr[(int)x]; // number of these presyns
    setdvi2(pov+k,dlv+k,dvt,1);
    k+=dvt;
  }
  return (double)k;
 
return _lsetdviv;
 }
 
static double _hoc_setdviv(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  setdviv (  );
 return(_r);
}
 
/*VERBATIM*/
static int finishdvi2 (struct ID0* p) {
  Point_process **da,**das;
  double *db,*dbs;
  int i, dvt;
  db=p->del;
  da=p->dvi; 
  dvt=p->dvt;
  dbs=(double*)malloc(dvt*sizeof(double)); // sorted delays
  das=(Point_process**)malloc(dvt*sizeof(Point_process*)); // parallel sorted dvi
  gsort2(db,da,dvt,dbs,das);
  p->del=dbs; p->dvi=das; // sorted versions
  free(db); free(da);
  p->sprob=(unsigned char*)realloc((void*)p->sprob,(size_t)dvt*sizeof(char));// release probability
  for (i=0;i<dvt;i++) p->sprob[i]=1; // start out with all firing
}
 
static int  finishdvir (  ) {
   
/*VERBATIM*/
  int iCell;
  for(iCell=0;iCell<cesz;iCell++){
    lop(ce,iCell);
    finishdvi2(qp);
  }
  return 0; }
 
static double _hoc_finishdvir(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 finishdvir (  );
 return(_r);
}
 
static int  finishdvi (  ) {
   
/*VERBATIM*/
  finishdvi2(IDP);
  return 0; }
 
static double _hoc_finishdvi(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 finishdvi (  );
 return(_r);
}
 
static int  setdvi (  ) {
   
/*VERBATIM*/
{
  int i,dvt,flag; double *d, *y;
  if (! ifarg(1)) {printf("setdvi(v1,v2[,flag]): v1:cell#s; v2:delays\n"); return; }
  ip=IDP; pg=ip->pg; // this should be called right after jitcondiv()
  if (ip->dead) return;
  dvt=vector_arg_px(1, &y);
  i=vector_arg_px(2, &d);
  if (ifarg(3)) flag=(int)*getarg(3); else flag=0;
  if (i!=dvt || i==0) {printf("setdvi() ERR vec sizes: %d %d\n",dvt,i); hxe();}
  setdvi2(y,d,dvt,flag);
  }
  return 0; }
 
static double _hoc_setdvi(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 setdvi (  );
 return(_r);
}
 
/*VERBATIM*/
// setdvi2(divid_vec,del_vec,div_cnt,flag)
// flag 1 means just augment, 0or2: sort by del, 0: clear lists and replace
static int setdvi2 (double *y,double *d,int dvt,int flag) {
  int i,j,ddvi; double *db, *dbs; unsigned char pdead; unsigned int b,e;
  Object *lb; Point_process *pnnt, **da, **das;
  ddvi=(int)DEAD_DIV;
  ip=IDP; 
  if (flag==0) { b=0; e=dvt; // begin to end
    if (ip->dvi) { 
      free(ip->dvi); free(ip->del); free(ip->sprob); 
      ip->dvt=0; ip->dvi=(Point_process**)0x0; ip->del=(double*)0x0; ip->sprob=(char *)0x0;
    } // make sure all null pointers for realloc
  } else { 
    if (ip->dvt==0) {ip->dvi=(Point_process**)0x0; ip->del=(double*)0x0; ip->sprob=(char *)0x0;}
    b=ip->dvt; 
    e=ip->dvt+dvt; // dvt is amount to grow
  }
  da=(Point_process **)realloc((void*)ip->dvi,(size_t)(e*sizeof(Point_process *)));
  db=(double*)realloc((void*)ip->del,(size_t)(e*sizeof(double)));
  for (i=b,j=0;j<dvt;j++) { // i thru da[] j thru y, k to append
    // div can grow at lower rate if dead cells are encountered
    if (!(lb=ivoc_list_item(ce,(unsigned int)y[j]))) {
      printf("INTF:callback %g exceeds %d for list ce\n",y[j],cesz); hxe(); }
      pnnt=(Point_process *)lb->u.this_pointer;
      if (ddvi==1 || !(pdead=(*(id0**)&(pnnt->_prop->dparam[2]))->dead)) {
        da[i]=pnnt; db[i]=d[j]; i++;
      }
  }
  if ((dvt=i)<e) { // will need to shrink these arrays
    da=(Point_process **)realloc((void*)da,(size_t)(e*sizeof(Point_process *)));
    db=(double*)realloc((void*)db,(size_t)(e*sizeof(double)));
  }
  ip->dvt=dvt; ip->del=db; ip->dvi=da;
  if (flag!=1) finishdvi2(ip); // do sort
}
 
static int  prune (  ) {
   
/*VERBATIM*/

  {
  id0* ppost; double *x, p; int nx,j,potype;
  ip=IDP; pg=ip->pg;
  if (hoc_is_double_arg(1)) { // prune a certain percent of targets
    p=*getarg(1);
    if (p<0 || p>1) {printf("INTF:pruneERR0:need # [0,1] to prune [ALL,NONE]: %g\n",p); hxe();}
    if (p==1.) printf("INTFpruneWARNING: pruning 100% of cell %d\n",ip->id);
    if (verbose && ip->dvt>dscrsz) {
      printf("INTFpruneB:Div exceeds dscrsz: %d>%d\n",ip->dvt,dscrsz); hxe(); }
    if (p==0.) {
      for (j=0;j<ip->dvt;j++) ip->sprob[j]=1; // unprune completely
      return; // now that unpruning is done, can return
    }
    potype=ifarg(2)?(int)*getarg(2):-1;
    sead=(ifarg(3))?(unsigned int)*getarg(3):GetDVIDSeedVal(ip->id);//seed for divergence and delays
    mcell_ran4(&sead, dscr , ip->dvt, 1.0); // random var (0,1)
    if(potype==-1){ // prune all types of synapses
      for (j=0;j<ip->dvt;j++) if (dscr[j]<p) ip->sprob[j]=0; // prune with prob p
    } else { // only prune synapses with postsynaptic type == potype
      for (j=0;j<ip->dvt;j++){
        ppost=*((id0**) &((ip->dvi[j]->_prop->dparam)[2])); // #define sop *_ppvar[2].pval
        if (ppost->type==potype && dscr[j]<p) ip->sprob[j]=0; // prune with prob p
      }
    }
  } else { // confusing arg1==0->sprob[j]=1 for all j; but arg1=[0] (a vector)->sprob[0]=0 
    if (verbose) printf("INTF WARNING prune(vec) deprecated: use intf.sprob(vec) instead\n");
    nx=vector_arg_px(1,&x);
    if (nx!=ip->dvt) {printf("INTF:pruneERRA:Wrong size vector:%d!=%d\n",nx,ip->dvt); hxe();}
    for (j=0;j<ip->dvt;j++) ip->sprob[j]=(unsigned char)x[j];
  }
  }
  return 0; }
 
static double _hoc_prune(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 prune (  );
 return(_r);
}
 
static int  sprob (  ) {
   
/*VERBATIM*/

  {
  double *x; int nx,j;
  ip=IDP; pg=ip->pg;
  nx=vector_arg_px(1,&x);
  if (nx!=ip->dvt) {printf("INTF:pruneERRA:Wrong size vector:%d!=%d\n",nx,ip->dvt); hxe();}
  if (ifarg(2)) { // "GET"
    if (!hoc_is_str_arg(2)) { printf("INTF sprob()ERRA: only legit 2nd arg is 'GET'\n"); hxe();
    } else for (j=0;j<ip->dvt;j++) x[j]=(double)ip->sprob[j];
  } else {
    for (j=0;j<ip->dvt;j++) ip->sprob[j]=(unsigned char)x[j];
  }
  }
  return 0; }
 
static double _hoc_sprob(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 sprob (  );
 return(_r);
}
 
static int  turnoff (  ) {
   
/*VERBATIM*/
{
  int nx,ny,i,j,k,dvt; double poid,*x,*y; Point_process **das; unsigned char off;
  nx=vector_arg_px(1,&x);
  ny=vector_arg_px(2,&y);
  if (ifarg(3)) off=(unsigned char)*getarg(3); else off=0;
  for (i=0;i<nx;i++) { 
    lop(ce,(unsigned int)x[i]); 
    dvt=qp->dvt; das=qp->dvi;
    for (j=0;j<dvt;j++) {
      ip=*((id0**) &((das[j]->_prop->dparam)[2])); // sop is *_ppvar[2].pval
      poid=(double)ip->id; // postsyn id
      for (k=0;k<ny;k++) {
        if (poid==y[k]) {
          qp->sprob[j]=off; break;
        }
      }
    }
  }
  }
  return 0; }
 
static double _hoc_turnoff(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 turnoff (  );
 return(_r);
}
 
/*VERBATIM*/

// gsort2() sorts 2 parallel vectors -- delays and Point_process pointers
int gsort2 (double *db, Point_process **da,int dvt,double *dbs, Point_process **das) {
  int i;
  scr=scrset(dvt);
  for (i=0;i<dvt;i++) scr[i]=i;
  nrn_mlh_gsort(db, scr, dvt, cmpdfn);
  for (i=0;i<dvt;i++) {
    dbs[i]=db[scr[i]];
    das[i]=da[scr[i]];
  }
}
 
static int  freedvi (  ) {
   
/*VERBATIM*/
  { 
    int i, poty; id0 *jp;
    jp=IDP;
    if (jp->dvi) {
      free(jp->dvi); free(jp->del); free(jp->sprob);
      jp->dvt=0; jp->dvi=(Point_process**)0x0; jp->del=(double*)0x0; jp->sprob=(char *)0x0;
    }
  }
  return 0; }
 
static double _hoc_freedvi(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 freedvi (  );
 return(_r);
}
 
static int  pgset (  ) {
   
/*VERBATIM*/
  ip->pg=pg; // set the local to the global
  return 0; }
 
static double _hoc_pgset(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 pgset (  );
 return(_r);
}
 
double qstats (  ) {
   double _lqstats;
 
/*VERBATIM*/
{
    double stt[3]; int lct,flag; FILE* tfo;
    if (ifarg(1)) {tfo=hoc_obj_file_arg(1); flag=1;} else flag=0;
    lct=cty[IDP->type];
    _lqstats = nrn_event_queue_stats(stt);
    printf("SPIKES: %d (%ld:%ld)\n",IDP->spkcnt,spikes[lct],blockcnt[lct]);
    printf("QUEUE: Inserted %g; removed %g\n",stt[0],stt[2]);
    if (flag) {
      fprintf(tfo,"SPIKES: %d (%ld:%ld);",IDP->spkcnt,spikes[lct],blockcnt[lct]);
      fprintf(tfo,"QUEUE: Inserted %g; removed %g remaining: %g\n",stt[0],stt[2],_lqstats);
    }
  }
 
return _lqstats;
 }
 
static double _hoc_qstats(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  qstats (  );
 return(_r);
}
 
double qsz (  ) {
   double _lqsz;
 
/*VERBATIM*/
{
    double stt[3];
    _lqsz = nrn_event_queue_stats(stt);
  }
 
return _lqsz;
 }
 
static double _hoc_qsz(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  qsz (  );
 return(_r);
}
 
static int  qclr (  ) {
   
/*VERBATIM*/
{
    clear_event_queue();
  }
  return 0; }
 
static double _hoc_qclr(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 qclr (  );
 return(_r);
}
 
static int  jitcondiv (  ) {
   
/*VERBATIM*/
{
  Symbol *sym; int i,j; unsigned int sz; char *name="ce";
  pg=(postgrp *)malloc(sizeof(postgrp));
  if (ifarg(1)) name = gargstr(1);
  sym = hoc_lookup(name); ce = (*(hoc_objectdata[sym->u.oboff].pobj));
  sym = hoc_lookup("CTYP"); CTYP = (*(hoc_objectdata[sym->u.oboff].pobj));
  if (installed==2.0) { // jitcondiv was previously run
    sz=ivoc_list_count(ce);
    if (sz==cesz) printf("\t**** INTF WARNING cesz unchanged: INTF(s) created off-list ****\n");
  } else installed=2.0;
  cesz = ivoc_list_count(ce);
  cty[0]=DP; cty[1]=SU; cty[2]=IN; // set the cell types
  CTYPi=HVAL("CTYPi"); STYPi=HVAL("STYPi"); dscrsz=HVAL("scrsz");
  pg->ix =HPTR("ix"); pg->ixe=HPTR("ixe"); 
  pg->dvg=HPTR("div"); pg->numc=HPTR("numc"); 
  pg->wmat=HPTR("wmat"); pg->wd0=HPTR("wd0");
  pg->delm=HPTR("delm"); pg->deld=HPTR("deld");
  dscr=HPTR("scr");
  if (!ce) {printf("INTF jitcondiv ERRA: ce not found\n"); hxe();}
  if (ivoc_list_count(CTYP)!=CTYPi){
    printf("INTF jitcondiv ERRB: %d %d\n",ivoc_list_count(CTYP),CTYPi); hxe(); }
  for (i=0;i<cesz;i++) { lop(ce,i); qp->pg=pg; } // set all of the pg pointers for now
  // make sure no seg error:
  printf("Checking for possible seg error in double arrays: CTYPi==%d: ",CTYPi);
  // can access arbitrary member dvg[a][b] using (&dvg[a*CTYPi])[b] or dvg+a*CTYPi+b
  printf("%d %d %d ",DVG(CTYPi-1,CTYPi-1),(int)pg->ix[CTYPi-1],(int)pg->ixe[CTYPi-1]);
  printf("%g %g ",WMAT(CTYPi-1,CTYPi-1,STYPi-1),WD0(CTYPi-1,CTYPi-1,STYPi-1));
  printf("%g %g ",DELM(CTYPi-1,CTYPi-1),DELD(CTYPi-1,CTYPi-1));
  printf("%d %g\n",dscrsz,dscr[dscrsz-1]); // scratch area for doubles
  for (i=0,j=0;i<CTYPi;i++) if (ctt(i,&name)!=0) {
    cty[j]=i; CNAME[j]=name;
    j++;
    if (j>=CTYPp) {printf("jitcondiv() INTERRA\n"); hxe();}
  }
  CTYN=j; // number of cell types being used
  for (i=0;i<CTYN;i++) printf("%s(%d)=%g ",CNAME[i],cty[i],NUMC(cty[i]));
  printf("\n%d cell types being used\n",CTYN);
  }
  return 0; }
 
static double _hoc_jitcondiv(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 jitcondiv (  );
 return(_r);
}
 
static int  jitrec (  ) {
   
/*VERBATIM*/
{
  int i;
  if (! ifarg(2)) { // clear with jitrec() or jitrec(0)
    jrmax=0; jridv=0x0; jrtvv=0x0;
    return;
  }
  i =   vector_arg_px(1, &jrid); // could just set up the pointers once
  jrmax=vector_arg_px(2, &jrtv);
  jridv=vector_arg(1); jrtvv=vector_arg(2);
  jrmax=vector_buffer_size(jridv);
  if (jrmax!=vector_buffer_size(jrtvv)) {
    printf("jitrec() ERRA: not same size: %d %d\n",i,jrmax); jrmax=0; hxe(); }
  jri=jrj=0; // needs to be set at beginning of run
  }
  return 0; }
 
static double _hoc_jitrec(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 jitrec (  );
 return(_r);
}
 
double scsv (  ) {
   double _lscsv;
 
/*VERBATIM*/
{
  int ty=4; int i,j; unsigned int cnt=0;
  name = gargstr(1);
  if ( !(wf1 = fopen(name,"w"))) { printf("Can't open %s\n",name); hxe(); }
  fwrite(&cesz,sizeof(int),1,wf1);
  fwrite(&ty,sizeof(int),1,wf1);
  for (i=0,j=0;i<cesz;i++,j++) { 
    lop(ce,i); 
    if (qp->spkcnt) {
      dscr[j]=(double)(qp->spkcnt); 
      cnt++;
    } else dscr[j]=0.0;
    if (j>=dscrsz) {
      fwrite(dscr,(size_t)sizeof(double),(size_t)dscrsz,wf1);
      fflush(wf1);
      j=0;
    }
  }
  if (j>0) fwrite(dscr,(size_t)sizeof(double),(size_t)j,wf1);
  fclose(wf1);
  _lscsv=(double)cnt;
  }
 
return _lscsv;
 }
 
static double _hoc_scsv(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  scsv (  );
 return(_r);
}
 
double spkcnt (  ) {
   double _lspkcnt;
 
/*VERBATIM*/
{
  int nx, ny, i,j, ix, c, min, max, flag; unsigned int sum; double *y,*x;
  nx=ny=min=max=flag=0; i=1;
  if (ifarg(i)) {
    if (hoc_is_object_arg(i)) { 
      ny = vector_arg_px(i, &y); i++;
    } else if (ifarg(i+1)) {
      min=(int)*getarg(i); max=(int)*getarg(i+1); i+=2;
    }
  }
  while (ifarg(i)) { // can pick up flag and vector in either order
    if (hoc_is_object_arg(i)) { // output to a vector
      nx = vector_arg_px(i, &x);
    } else flag=(int)*getarg(i);
    i++;
  }
  if (ny) max=ny; else if (max==0) max=cesz; else max+=1; // enter max index wish to graph
  if (nx && nx!=max-min) {
    printf("INTF spkcnt() ERR: Vectors not same size %d %d\n",nx,max-min);hxe();}
  for  (i=min, sum=0;i<max;i++) { 
    if (ny) lop(ce,(int)y[i]); else lop(ce,i);
    if (flag==2) sum+=(c=qp->blkcnt); else sum+=(c=qp->spkcnt);
    if (nx) x[i]=(double)c;
    if (flag==1) qp->spkcnt=qp->blkcnt=0;
  }
  _lspkcnt=(double)sum;
  }
 
return _lspkcnt;
 }
 
static double _hoc_spkcnt(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  spkcnt (  );
 return(_r);
}
 
static int  probejcd (  ) {
   
/*VERBATIM*/
{  int i,a[4];
    for (i=1;i<=3;i++) a[i]=(int)*getarg(i);
    printf("CTYPi: %d, STYPi: %d, ",CTYPi,STYPi);
    // printf("div: %d, ix: %d, ixe: %d, ",DVG(a[1],a[2]),(int)ix[a[1]],(int)ixe[a[1]]);
    printf("wmat: %g, wd0: %g\n",WMAT(a[1],a[2],a[3]),WD0(a[1],a[2],a[3]));
  }
  return 0; }
 
static double _hoc_probejcd(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 probejcd (  );
 return(_r);
}
 
static int  randspk (  ) {
   
/*VERBATIM*/

  ip=IDP;  
  if (ip->rvi > ip->rve) { // pointers go from rvi to rve inclusive
    ip->input=0;           // turn off
    nxt=-1.;
  } else if (t==0) {     // initialization
    nxt=vsp[ip->rvi];
    WEX=wsp[ip->rvi++];
  } else {     // absolute times in vector -> interval
    while ((nxt=vsp[ip->rvi++]-t)<=1e-6) { 
      if (ip->rvi-1 > ip->rve) { printf("randspk() ERRA: "); chk(2.); hxe(); }
    }
    WEX=wsp[ip->rvi-1]; // rvi was incremented
  }
  return 0; }
 
static double _hoc_randspk(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 randspk (  );
 return(_r);
}
 
static int  vers (  ) {
   printf ( "$Id: intf.mod,v 1.853 2010/09/12 15:07:45 samn Exp $\n" ) ;
    return 0; }
 
static double _hoc_vers(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 vers (  );
 return(_r);
}
 
/*VERBATIM*/
double val (double xx, double ta) { 
  vii[1]=VAM*EXP(-(xx - ta)/tauAM);
  vii[2]=VNM*EXP(-(xx - ta)/tauNM);
  vii[3]=VGA*EXP(-(xx - ta)/tauGA);
  if (VGBdel>0) {
    vii[4]=esinr(xx-tGB);
  } else {
    vii[4]=VGB*EXP(-(xx - ta)/tauGB);
  }  
  vii[5]=AHP*EXP(-(xx - ta)/tauahp);
  vii[6]=vii[1]+vii[2]+vii[3]+vii[4]+vii[5];
  vii[7]=VTH + (VTHR-VTH)*EXP(-(xx-trrs)/tauRR);
}
 
/*VERBATIM*/
double valps (double xx, double ta) { 
  vii[1]=VAM*EXP(-(xx - ta)/tauAM);
  vii[2]=VNM*EXP(-(xx - ta)/tauNM);
  vii[3]=VGA*EXP(-(xx - ta)/tauGA);
  vii[4]=esinr(xx-tGB);
  // vii[5]=AHP*EXP(-(xx - ta)/tauahp);
  vii[6]=vii[1]+vii[2]-vii[3];
}
 
static int  record (  ) {
   
/*VERBATIM*/
{
  int i,j,k,nz; double ti;
  vp = SOP;
  if (tg>=t) return;
  if (ip->record==1) {
    while ((int)vp->p >= (int)vp->size-(int)((t-tg)/vdt)-10) { 
      vp->size*=2;
      for (k=0;k<NSV;k++) if (vp->vv[k]!=0x0) vp->vvo[k]=vector_newsize(vp->vv[k], vp->size);
      // printf("**** WARNING expanding recording room to %d (type%d id%d at %g)****\n",vp->size,IDP->type,IDP->id,t);
    }
  } else if ((int)vp->p > (int)vp->size-(int)((t-tg)/vdt)) { // shift if record==2
    nz=(int)((t-tg)/vdt);
    for (k=0;k<NSV;k++) if (vp->vv[k]!=0x0) {
      if (nz>vp->size) {pid(); printf("Record WARNING: vec too short: %d %d\n",nz,vp->size);
        vp->p=0;
      } else {
        for (i=nz,j=0; i<vp->size; i++,j++) vp->vvo[k][j]=vp->vvo[k][i];
        vp->p=vp->size-nz;
      }
    }
  }
  for (ti=tg;ti<=t && vp->p < vp->size;ti+=vdt,vp->p++) { 
    val(ti,tg);  
    if (vp->vvo[0]!=0x0) vp->vvo[0][vp->p]=ti;
    for (k=1;k<NSV-1;k++) if (vp->vvo[k]!=0x0) { // not nil pointer
      vp->vvo[k][vp->p]=vii[k]+RMP;
    }
    for (;k<NSV;k++) if (vp->vvo[k]!=0x0) { // not nil pointer
      vp->vvo[k][vp->p]=vii[k]; 
    }
  }
  tg=t;
  }
  return 0; }
 
static double _hoc_record(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 record (  );
 return(_r);
}
 
static int  recspk (  double _lx ) {
   
/*VERBATIM*/
{ int k;
  vp = SOP;
  record();
  if (vp->p > vp->size || vp->vvo[6]==0) return; 
  if (vp->vvo[0]!=0x0) vp->vvo[0][vp->p-1]=_lx;
  vp->vvo[6][vp->p-1]=spkht; // the spike
  tg=_lx;
  }
  return 0; }
 
static double _hoc_recspk(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 recspk (  *getarg(1) );
 return(_r);
}
 
static int  recclr (  ) {
   
/*VERBATIM*/

  {int k;
  if (IDP->record) {
    if (SOP!=nil) {
      vp = SOP;
      vp->size=0; vp->p=0;
      for (k=0;k<NSV;k++) { vp->vv[k]=nil; vp->vvo[k]=nil; }
    } else printf("INTF recclr ERR: nil pointer\n");
  }
  IDP->record=0;
  }
  return 0; }
 
static double _hoc_recclr(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 recclr (  );
 return(_r);
}
 
static int  recfree (  ) {
   
/*VERBATIM*/
  if (SOP!=nil) {
    free(SOP);
    SOP=nil;
  } else printf("INTF recfree ERR: nil pointer\n");
  IDP->record=0;
  return 0; }
 
static double _hoc_recfree(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 recfree (  );
 return(_r);
}
 
static int  initvspks (  ) {
   
/*VERBATIM*/

  {int max, i,err;
    double last,lstt;
    if (! ifarg(1)) {printf("Return initvspks(ivspks,vspks,wvspks)\n"); return 0.;}
    if (isp!=NULL) clrvspks();
    ip=IDP;  err=0;
    i = vector_arg_px(1, &isp); // could just set up the pointers once
    max=vector_arg_px(2, &vsp);
    if (max!=i) {err=1; printf("initvspks ERR: vecs of different size\n");}
    if (max==0) {err=1; printf("initvspks ERR: vec not initialized\n");}
    max=vector_arg_px(3, &wsp);
    if (max!=i) {err=1; printf("initvspks ERR: 3rd vec is of different size\n");}
    vspn=max;
    if (!ce) {printf("Need global ce for initvspks() since intf.mod501\n"); hxe();}
    for (i=0,last=-1; i<max; ) { // move forward to first
      if (isp[i]!=last) { // new one
        lop(ce,(unsigned int)isp[i]);
        qp->rvb=qp->rvi=i;
        qp->vinflg=1;
        last=isp[i];
        lstt=vsp[i];
        i++;
      }
      for (; i<max && isp[i] == last; i++) { // move forward to last
        if (vsp[i]<=lstt) { err=1; 
          printf("initvspks ERR: nonmonotonic for cell#%d: %g %g\n",qp->id,lstt,vsp[i]); }
          lstt=vsp[i];
      }
      qp->rve=i-1;
      if (subsvint>0) { 
        vsp[qp->rve] = vsp[qp->rvb]+subsvint;
        wsp[qp->rve] = wsp[qp->rvb];
      }
      if (err) { qp->rve=0; hxe(); }
    }
  }
  return 0; }
 
static double _hoc_initvspks(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 initvspks (  );
 return(_r);
}
 
static int  shock (  ) {
   
/*VERBATIM*/

  {int max, i,err;
    double last, lstt, *isp, *vsp, *wsp;
    if (! ifarg(1)) {printf("Return shock(ivspks,vspks,wvspks)\n"); return 0.;}
    ip=IDP;  err=0;
    i = vector_arg_px(1, &isp); // could just set up the pointers once
    max=vector_arg_px(2, &vsp);
    if (max!=i) {err=1; printf("shock ERR: vecs of different size\n");}
    if (max==0) {err=1; printf("shock ERR: vec not initialized\n");}
    max=vector_arg_px(3, &wsp);
    if (max!=i) {err=1; printf("shock ERR: 3rd vec is of different size\n");}
    vspn=max;
    if (!ce) {printf("Need global ce for shock()\n"); hxe();}
    for (i=0,last=-1; i<max; ) { // move forward to first
      if (isp[i]!=last) { // skip any redund indices
        lop(ce,(unsigned int)isp[i]);
        WEX=-1e9; // code for shock
  #if defined(t)
        net_send((void**)0x0, wts,pmt,t+vsp[i],2.0); // 2 is randspk flag
  #else
        net_send((void**)0x0, wts,pmt,vsp[i],2.0); // 2 is randspk flag
  #endif
        i++;
      }
    }
  }
  return 0; }
 
static double _hoc_shock(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 shock (  );
 return(_r);
}
 
static int  clrvspks (  ) {
   
/*VERBATIM*/
{
 unsigned int i;
 for (i=0; i<cesz; i++) {
   lop(ce,i);
   qp->vinflg=0;
 }   
 }
  return 0; }
 
static double _hoc_clrvspks(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 clrvspks (  );
 return(_r);
}
 
static int  trvsp (  ) {
   
/*VERBATIM*/

  int i, flag; 
  double ind, t0;
  ip=IDP;
  flag=(int) *getarg(1);
  if (subsvint==0.) {printf("trvsp"); return(0.);}
  ind=isp[0]; t0=vsp[0];
  if (flag==1) {
    for (i=0; i<vspn; i++) {
      if (isp[i]!=ind) {
        vsp[i-1]=1.e9;
        ind=isp[i];
      }
    }
    vsp[vspn-1]=1.e9;
  } else if (flag==2) {
    for (i=0; i<vspn; i++) {
      if (isp[i]!=ind) {
        vsp[i-1]=t0+subsvint;
        ind=isp[i]; t0=vsp[i];
      }
    }
    vsp[vspn-1]=t0+subsvint;
  } else {printf("trvsp flag %d not recognized\n",flag); hxe();}
  return 0; }
 
static double _hoc_trvsp(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 trvsp (  );
 return(_r);
}
 
static int  initjttr (  ) {
   
/*VERBATIM*/

  {int max, i, err=0;
    jtpt=0;
    if (! ifarg(1)) {printf("Return initjttr(vec)\n"); return(0.);}
    max=vector_arg_px(1, &jsp);
    if (max==0) {err=1; printf("initjttr ERR: vec not initialized\n");}
    for (i=0; i<max; i++) if (jsp[i]<=0) {err=1;
      printf("initjttr ERR: vec should be >0: %g\n",jsp[i]);}
    if (err) { jsp=nil; jtmax=0.; return(0.); }// hoc_execerror("",0);
    if (max != jtmax) {
      printf("WARNING: resetting jtmax_INTF to %d\n",max); jtmax=max; }
  }
  return 0; }
 
static double _hoc_initjttr(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 initjttr (  );
 return(_r);
}
 
/*VERBATIM*/
//** lop(LIST,ITEM#) sets qp
// modeled on vector_arg_px(): picks up obj from list and resolves pointers
static double* lop (Object *ob, unsigned int i) {
  Object *lb;
  lb = ivoc_list_item(ob, i);
  if (! lb) { printf("INTF:lop %d exceeds %d for list ce\n",i,cesz); hxe();}
  pmt=ob2pntproc(lb);
  qp=*((id0**) &((pmt->_prop->dparam)[2])); // #define sop *_ppvar[2].pval
  // _hoc_setdata((void*)pmt); // make all the range vars accessible
  _p=pmt->_prop->param; _ppvar=pmt->_prop->dparam;
  return pmt->_prop->param;
}

// use stoppo() as a convenient conditional breakpoint in gdb (gdb watching is too slow)
int stoppo () {
}

//** ctt(ITEM#) find cells that exist by name
static int ctt (unsigned int i, char** name) {
  Object *lb;
  if (NUMC(i)==0) return 0; // none of this cell type
  lb = ivoc_list_item(CTYP, i);
  if (! lb) { printf("INTF:ctt %d exceeds %d for list CTYP\n",i,CTYPi); hxe();}
  {*name=*(lb->u.dataspace->ppstr);}
  return (int)NUMC(i);
}
 
static int  test (  ) {
   
/*VERBATIM*/
  char *str; int x;
  x=ctt(7,&str); 
  printf("%s (%d)\n",str,x);
  return 0; }
 
static double _hoc_test(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 test (  );
 return(_r);
}
 
static int  lof (  ) {
   
/*VERBATIM*/
{
  Object *ob; int num,i,ii,j,k,si,nx;  double *vvo[7], *par; void *vv[7];
  ob = *(hoc_objgetarg(1));
  si=(int)*getarg(2);
  num = ivoc_list_count(ob);
  if (num!=7) { printf("INTF lof ERR %d>7\n",num); hxe(); }
  for (i=0;i<num;i++) { 
    j = list_vector_px3(ob, i, &vvo[i], &vv[i]);
    if (i==0) nx=j;
    if (j!=nx) { printf("INTF lof ERR %d %d\n",j,nx); hxe(); }
  }
  //  for (i=ix[si],ii=0;i<=ixe[si] && ii<nx;i++,ii++) {
  //   vvo[0][ii]=(double)i;
  //   par=lop(ce,i);
  //   for (j=20,k=1;j<25;j++,k++) { // NB these could move: Vm,VAM,VNM,VGA,VGB
  //     vvo[k][ii]=par[j];
  //   }
  // }
 }
  return 0; }
 
static double _hoc_lof(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 lof (  );
 return(_r);
}
 
static int  initinvl (  ) {
   printf ( "initinvl() NOT BEING USED\n" ) ;
    return 0; }
 
static double _hoc_initinvl(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 initinvl (  );
 return(_r);
}
 
double invlflag (  ) {
   double _linvlflag;
 
/*VERBATIM*/
  ip=IDP;
  if (ip->invl0==1 && invlp==nil) { // err
    printf("INTF invlflag ERR: pointer not initialized\n"); hoc_execerror("",0); 
  }
  _linvlflag= (double)ip->invl0;
 
return _linvlflag;
 }
 
static double _hoc_invlflag(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  invlflag (  );
 return(_r);
}
 
double shift (  double _lvl ) {
   double _lshift;
 
/*VERBATIM*/
  
  double expand, tmp, min, max;
//if (invlp==nil) {printf("INTF invlflag ERRa: pointer not initialized\n"); hoc_execerror("",0);}
  if ((t<(invlt-invl)+invl/2) && invlt != -1) { // don't shift if less than halfway through
    _lshift=0.;  // flag for no shift
  } else {
    expand = -(_lvl-(-65))/20; // expand positive if hyperpolarized
    if (expand>1.) expand=1.; if (expand<-1.) expand=-1.;
    if (expand>0.) { // expand interval
      max=1.5*invl;
      tmp=oinvl+0.8*expand*(max-oinvl); // the amount we can add to the invl
    } else {
      min=0.5*invl; 
      tmp=oinvl+0.8*expand*(oinvl-min); // the amount we can reduce current invl
    }
    if (invlt+tmp<t+2) { // getting too near spike time
      _lshift=0.;
    } else {
      oinvl=tmp; // new interval
      _lshift=invlt+oinvl;
    }
  }
 
return _lshift;
 }
 
static double _hoc_shift(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  shift (  *getarg(1) );
 return(_r);
}
 
static int  recini (  ) {
   
/*VERBATIM*/

  { int k;
  if (SOP==nil) { 
    printf("INTF record ERR: pointer not initialized\n"); hoc_execerror("",0); 
  } else {
    vp = SOP;
    vp->p=0;
    // open up the vector maximally before writing into it; will correct size in fini
    for (k=0;k<NSV;k++) if (vp->vvo[k]!=0) vector_resize(vp->vv[k], vp->size);
  }}
  return 0; }
 
static double _hoc_recini(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 recini (  );
 return(_r);
}
 
static int  fini (  ) {
   
/*VERBATIM*/

  {int k;
  // initialization for next round, this will not be set if job terminates prematurely
  IDP->rvi=IDP->rvb;  // -- see vinset()
  if (IDP->wrec) { wrecord(1e9); }
  if (IDP->record) {
    record(); // finish up
    for (k=0;k<NSV;k++) if (vp->vvo[k]!=0) { // not nil pointer
      vector_resize(vp->vv[k], vp->p);
    }
  }}
  return 0; }
 
static double _hoc_fini(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 fini (  );
 return(_r);
}
 
static int  chk (  double _lf ) {
   
/*VERBATIM*/

  {int i,lfg;
  lfg=(int)_lf;
  ip=IDP;
  printf("ID:%d; typ: %d; rec:%d wrec:%d inp:%d jtt:%d invl:%d\n",ip->id,ip->type,ip->record,ip->wrec,ip->input,ip->jttr,ip->invl0);
  if (lfg==1) {
    if (SOP!=nil) {
      vp = SOP;
      printf("p %d size %d tg %g\n",vp->p,vp->size,tg);
      for (i=0;i<NSV;i++) if (vp->vv[i]) printf("%d %x %x;",i,(unsigned int)vp->vv[i],(unsigned int)vp->vvo[i]);
    } else printf("Recording pointers not initialized");
  }
  if (lfg==2) { 
    printf("Global vectors for input and jitter (jttr): \n");
    if (vsp!=nil) printf("VSP: %x (%d/%d-%d)\n",(unsigned int)vsp,ip->rvi,ip->rvb,ip->rve); else printf("no VSP\n");
    if (jsp!=nil) printf("JSP: %x (%d/%d)\n",(unsigned int)jsp,jtpt,jtmax); else printf("no JSP\n");
  }
  if (lfg==3) { 
    if (vsp!=nil) { printf("VSP: (%d/%d-%d)\n",ip->rvi,ip->rvb,ip->rve); 
      for (i=ip->rvb;i<=ip->rve;i++) printf("%d:%g  ",i,vsp[i]);
      printf("\n");
    } else printf("no VSP\n");
  }
  if (lfg==4) {  // was used to give invlp[],invlmax
  }
  if (lfg==5) { 
    printf("wwpt %d wwsz %d\n WW vecs: ",wwpt,wwsz);
    printf("wwwid %g wwht %d nsw %g\n WW vecs: ",wwwid,(int)wwht,nsw);
    for (i=0;i<NSW;i++) printf("%d %x %x;",i,(unsigned int)ww[i],(unsigned int)wwo[i]);
  }}
  return 0; }
 
static double _hoc_chk(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 chk (  *getarg(1) );
 return(_r);
}
 
double pid (  ) {
   double _lpid;
 
/*VERBATIM*/

  printf("INTF%d(%d/%d@%g) ",IDP->id,IDP->type,IDP->col,t);
  _lpid = (double)IDP->id;
 
return _lpid;
 }
 
static double _hoc_pid(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  pid (  );
 return(_r);
}
 
double id (  ) {
   double _lid;
 
/*VERBATIM*/
  if (ifarg(1)) IDP->id = (unsigned int) *getarg(1);
  _lid = (double)IDP->id;
 
return _lid;
 }
 
static double _hoc_id(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  id (  );
 return(_r);
}
 
double type (  ) {
   double _ltype;
 
/*VERBATIM*/
  if (ifarg(1)) IDP->type = (unsigned char) *getarg(1);
  _ltype = (double)IDP->type;
 
return _ltype;
 }
 
static double _hoc_type(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  type (  );
 return(_r);
}
 
double col (  ) {
   double _lcol;
 
/*VERBATIM*/

  ip = IDP; 
  if (ifarg(1)) ip->col = (unsigned int) *getarg(1);
  _lcol = (double)ip->col;
 
return _lcol;
 }
 
static double _hoc_col(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  col (  );
 return(_r);
}
 
double dbx (  ) {
   double _ldbx;
 
/*VERBATIM*/

  ip = IDP; 
  if (ifarg(1)) ip->dbx = (unsigned char) *getarg(1);
  _ldbx = (double)ip->dbx;
 
return _ldbx;
 }
 
static double _hoc_dbx(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  dbx (  );
 return(_r);
}
 
static int  initrec (  ) {
   
/*VERBATIM*/

  {int i;
  name = gargstr(1);
  if (SOP==nil) { 
    IDP->record=1;
    SOP = (vpt*)ecalloc(1, sizeof(vpt));
    SOP->size=0;
  }
  if (IDP->record==0) {
    recini();
    IDP->record=1;
  }
  vp = SOP;
  i=(int)varnum();
  if (i==-1) {printf("INTF record ERR %s not recognized\n",name); hoc_execerror("",0); }
  vp->vv[i]=vector_arg(2);
  vector_arg_px(2, &(vp->vvo[i]));
  if (vp->size==0) { vp->size=(unsigned int)vector_buffer_size(vp->vv[i]);
  } else if (vp->size != (unsigned int)vector_buffer_size(vp->vv[i])) {
    printf("INTF initrec ERR vectors not all same size: %d vs %d",vp->size,vector_buffer_size(vp->vv[i]));
    hoc_execerror("", 0); 
  }} 
  return 0; }
 
static double _hoc_initrec(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 initrec (  );
 return(_r);
}
 
double varnum (  ) {
   double _lvarnum;
 double _li ;
 _li = - 1.0 ;
   
/*VERBATIM*/
  if (strcmp(name,"time")==0)      { _li=0.;
  } else if (strcmp(name,"VAM")==0) { _li=1.;
  } else if (strcmp(name,"VNM")==0) { _li=2.;
  } else if (strcmp(name,"VGA")==0) { _li=3.;
  } else if (strcmp(name,"VGB")==0) { _li=4.;
  } else if (strcmp(name,"AHP")==0) { _li=5.;
  } else if (strcmp(name,"V")==0) { _li=6.;
  } else if (strcmp(name,"VM")==0) { _li=6.; // 2 names for V
  } else if (strcmp(name,"VTHC")==0) { _li=7.;
  }
 _lvarnum = _li ;
   
return _lvarnum;
 }
 
static double _hoc_varnum(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  varnum (  );
 return(_r);
}
 
static int  vecname (  ) {
   
/*VERBATIM*/
  int i; 
  i = (int)*getarg(1);
  if (i==0)      printf("time\n");
  else if (i==1) printf("VAM\n");
  else if (i==2) printf("VNM\n");
  else if (i==3) printf("VGA\n");
  else if (i==4) printf("VGB\n");
  else if (i==5) printf("AHP\n");
  else if (i==6) printf("V\n");
  else if (i==7) printf("VTHC\n");
  return 0; }
 
static double _hoc_vecname(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 vecname (  );
 return(_r);
}
 
static int  initwrec (  ) {
   
/*VERBATIM*/

  {int i, k, num, cap;  Object* ob;
    ob =   *hoc_objgetarg(1); // list of vectors
    num = ivoc_list_count(ob);
    if (num>NSW) { printf("INTF initwrec() WARN: can only store %d ww vecs\n",NSW); hxe();}
    nsw=(double)num;
    for (k=0;k<num;k++) {
      cap = list_vector_px2(ob, k, &wwo[k], &ww[k]);
      if (k==0) wwsz=cap; else if (wwsz!=cap) {
        printf("INTF initwrec ERR w-vecs size err: %d,%d,%d",k,wwsz,cap); hxe(); }
    }
  }
  return 0; }
 
static double _hoc_initwrec(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 initwrec (  );
 return(_r);
}
 static double _mfac_popspk, _tmin_popspk;
 static void _check_popspk();
 static void _check_popspk() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_wwwid;
  static double _sav_wwht;
  if (!usetable) {return;}
  if (_sav_wwwid != wwwid) { _maktable = 1;}
  if (_sav_wwht != wwht) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_popspk =  - 40.0 ;
   _tmax =  40.0 ;
   _dx = (_tmax - _tmin_popspk)/81.; _mfac_popspk = 1./_dx;
   for (_i=0, _x=_tmin_popspk; _i < 82; _x += _dx, _i++) {
    _f_popspk(_x);
    _t_Psk[_i] = Psk;
   }
   _sav_wwwid = wwwid;
   _sav_wwht = wwht;
  }
 }

 static int popspk(double _lx){ _check_popspk();
 _n_popspk(_lx);
 return 0;
 }

 static void _n_popspk(double _lx){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_popspk(_lx); return; 
}
 _xi = _mfac_popspk * (_lx - _tmin_popspk);
 if (isnan(_xi)) {
  Psk = _xi;
  return;
 }
 if (_xi <= 0.) {
 Psk = _t_Psk[0];
 return; }
 if (_xi >= 81.) {
 Psk = _t_Psk[81];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 Psk = _t_Psk[_i] + _theta*(_t_Psk[_i+1] - _t_Psk[_i]);
 }

 
static int  _f_popspk (  double _lx ) {
   Psk = - wwht * exp ( - 2. * _lx * _lx / wwwid / wwwid ) ;
    return 0; }
 
static double _hoc_popspk(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
  _r = 1.;
 popspk (  *getarg(1) );
 return(_r);
}
 
static int  pskshowtable (  ) {
   
/*VERBATIM*/

  int j;
  printf("_tmin_popspk:%g -_tmin_popspk:%g\n",_tmin_popspk,-_tmin_popspk);
  for (j=0;j<=-2*(int)_tmin_popspk+1;j++) printf("%g ",_t_Psk[j]);
  printf("\n");
  return 0; }
 
static double _hoc_pskshowtable(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 pskshowtable (  );
 return(_r);
}
 
static int  wrecord (  double _lte ) {
   
/*VERBATIM*/

  {int i,j,k,max,wrp; double ti,scale;
  for (i=0;i<WRNUM && (wrp=(int)IDP->wreci[i])>-1;i++) {
    // wrp: index for multiple field recordings
    scale=(double)IDP->wscale[i];
    if (_lte<1.e9) { // a spike recording
      if (scale>0) {
        max=-(int)_tmin_popspk; // max of table max=-min
        k=(int)floor((_lte-rebeg)/vdt+0.5);
        for (j= -max;j<=max && k+j>0 && k+j<wwsz;j++) {
          wwo[wrp][k+j] += scale*_t_Psk[j+max]; // direct copy from the Psk table
        }
      }
    } else if (twg>=t) { return;
    } else {
      for (ti=twg,k=(int)floor((twg-rebeg)/vdt+0.5);ti<=t && k<wwsz;ti+=vdt,k++) { 
        valps(ti,twg);  // valps() for pop spike calculation
        wwo[wrp][k]+=vii[6];
        if (IDP->dbx==-1) printf("%g:%g ",vii[6],wwo[wrp][k]);
      }
    }
  }
  if (_lte==1.e9) twg=ti;
  }
  return 0; }
 
static double _hoc_wrecord(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 wrecord (  *getarg(1) );
 return(_r);
}
 
double wrec (  ) {
   double _lwrec;
 
/*VERBATIM*/
  { int k,ix;
  ip=IDP; 
  if (ifarg(1)) {
    ix=(int)*getarg(1);
    if (ix>=1) {
      if (ix-1>=nsw) {
        printf("Attempt to save into ww[%d] but only have %d\n",ix-1,(int)nsw); hxe();}
      ip->wrec=1;
      ip->wreci[0]=(char)ix-1;
      ip->wscale[0]=1.; // default
      if (ifarg(2)) ip->wscale[0]= (float)*getarg(2); 
    } else if (ix<=0) {
      ip->wrec=0;
      for (k=0;k<WRNUM;k++) { ip->wreci[k]=-1; ip->wscale[k]=-1.0; }
    } else {printf("INTF wrec ERR flag(0/1) %d\n",ip->wrec); hxe();
    }
  }
  _lwrec=(double)ip->wrec;
  }
 
return _lwrec;
 }
 
static double _hoc_wrec(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  wrec (  );
 return(_r);
}
 
double wrc (  ) {
   double _lwrc;
 
/*VERBATIM*/
  { int i,ix;
  ip=IDP; 
  if (ifarg(1)) {  // 1 or 2 args
    ix=(int)*getarg(1);
    if (ix<0) {
      ip->wrec=0;
      for (i=0;i<WRNUM;i++) { ip->wreci[i]=-1; ip->wscale[i]=-1.0; }
    } else {
      for (i=0;i<WRNUM && ip->wreci[i]!=-1 && ip->wreci[i]!=ix;i++) {};
      if (i==WRNUM) {
        pid(); printf("INFT wrc() ERR: out of wreci pointers (max %d)\n",WRNUM); hxe();}
      if (ix>=nsw) {printf("Attempt to save into ww[%d] but only have %d\n",ix,(int)nsw); hxe();}
      ip->wrec=1; 
      ip->wreci[i]=ix;
      if (ifarg(2)) ip->wscale[i]=(float)*getarg(2); else ip->wscale[i]=1.0;
    }
  } else {
    for (i=0;i<WRNUM;i++) printf("%d:%g ",ip->wreci[i],ip->wscale[i]);
    printf("\n");
  }
  _lwrc=(double)ip->wrec;
  }
 
return _lwrc;
 }
 
static double _hoc_wrc(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  wrc (  );
 return(_r);
}
 
double wwszset (  ) {
   double _lwwszset;
 
/*VERBATIM*/
  if (ifarg(1)) wwsz = (unsigned int) *getarg(1);
  _lwwszset=(double)wwsz;
 
return _lwwszset;
 }
 
static double _hoc_wwszset(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  wwszset (  );
 return(_r);
}
 
double wwfree (  ) {
   double _lwwfree;
 
/*VERBATIM*/
  int k;
  IDP->wrec=0;
  wwsz=0; wwpt=0; nsw=0.;
  for (k=0;k<NSW;k++) { ww[k]=nil; wwo[k]=nil; }
 
return _lwwfree;
 }
 
static double _hoc_wwfree(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  wwfree (  );
 return(_r);
}
 
double jttr (  ) {
   double _ljttr;
 
/*VERBATIM*/

  if (jtmax>0 && jtpt>=jtmax) {  
    jtpt=0;
    printf("Warning, cycling through jttr vector at t=%g\n",t);
  }
  if (jtmax>0) _ljttr = jsp[jtpt++]; else _ljttr=0;
 
return _ljttr;
 }
 
static double _hoc_jttr(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  jttr (  );
 return(_r);
}
 
static int  global_init (  ) {
   popspk ( _threadargscomma_ 0.0 ) ;
   
/*VERBATIM*/

  { int i,j,k; double stt[3];
  if (jridv) { jri=jrj=0; vector_resize(jridv, jrmax); vector_resize(jrtvv, jrmax); }
  if (nsw>0. && wwo[0]!=0) { // do just once
    printf("Initializing ww to record for %g (%g)\n",vdt*wwsz,vdt);
    wwpt=0;
    for (k=0;k<(int)nsw;k++) {
      vector_resize(ww[k], wwsz);
      for (j=0;j<wwsz;j++) wwo[k][j]=0.;
    }
  }
  spktot=0;
  jtpt=0;
  eventtot=0;
  errflag=0;
  for (i=0;i<CTYN;i++) blockcnt[cty[i]]=spikes[cty[i]]=0;
  }
  return 0; }
 
static double _hoc_global_init(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 global_init (  );
 return(_r);
}
 
static int  global_fini (  ) {
   
/*VERBATIM*/
  int k;
  for (k=0;k<(int)nsw;k++) vector_resize(ww[k], (int)floor(t/vdt+0.5));
  if (jridv && jrj<jrmax) {
    vector_resize(jridv, jrj); 
    vector_resize(jrtvv, jrj);
  }
  return 0; }
 
static double _hoc_global_fini(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 global_fini (  );
 return(_r);
}
 
double fflag (  ) {
   double _lfflag;
 _lfflag = 1.0 ;
   
return _lfflag;
 }
 
static double _hoc_fflag(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  fflag (  );
 return(_r);
}
 
double thrh (  ) {
   double _lthrh;
 _lthrh = VTH - RMP ;
   
return _lthrh;
 }
 
static double _hoc_thrh(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  thrh (  );
 return(_r);
}
 
double recflag (  ) {
   double _lrecflag;
 
/*VERBATIM*/
  _lrecflag= (double)IDP->record;
 
return _lrecflag;
 }
 
static double _hoc_recflag(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  recflag (  );
 return(_r);
}
 
double vinflag (  ) {
   double _lvinflag;
 
/*VERBATIM*/
  ip=IDP;
  if (ip->vinflg==0 && vsp==nil) { // do nothing
  } else if (ip->vinflg==1 && ip->rve==-1) {
    printf("INTF vinflag ERR: pointer not initialized\n"); hoc_execerror("",0); 
  } else if (ip->rve >= 0) { 
    if (vsp==nil) {
      printf("INTF vinflag ERR1: pointer not initialized\n"); hoc_execerror("",0); 
    }
    ip->rvi=ip->rvb;
    ip->input=1;
  }
  _lvinflag= (double)ip->vinflg;
 
return _lvinflag;
 }
 
static double _hoc_vinflag(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  vinflag (  );
 return(_r);
}
 
double flag (  ) {
   double _lflag;
 
/*VERBATIM*/
  char *sf; static int ix,fi,setfl,nx; static unsigned char val; static double *x, delt;
  if (FLAG==OK) { // callback -- DO NOT SET FROM HOC
    FLAG=0.;
    if (stoprun) {slowset=0; return;}
    if (IDP->dbx==-1)printf("slowset fi:%d ix:%d ss:%g delt:%g t:%g\n",fi,ix,slowset,delt,t);
    if (t>slowset || ix>=cesz) {  // done
      printf("Slow-setting of flag %d finished at %g: (%d,%g,%g)\n",fi,t,ix,delt,slowset); 
      slowset=0.; return;
    }
    if (ix<cesz) {
      lop(ce,ix);
      (&qp->type)[fi]=((fi>=iflneg)?(char)x[ix]:(unsigned char)x[ix]);
      ix++;
      #if defined(t)
      net_send((void**)0x0, wts,tpnt,t+delt,OK); // OK is flag() flag
      #else
      net_send((void**)0x0, wts,tpnt,delt,OK);
      #endif
    }
    return;
  }  
  if (slowset>0 && ifarg(3)) {
    printf("INTF flag() slowset ERR; attempted set during slowset: fi:%d ix:%d ss:%g delt:%g t:%g",\
           fi,ix,slowset,delt,t); 
    return;
  }
  ip = IDP; setfl=ifarg(3); 
  if (ifarg(4)) { slowset=*getarg(4); delt=slowset/cesz; slowset+=t; } 
  sf = gargstr(1);
  for (fi=0;fi<iflnum && strncmp(sf, &iflags[fi*4], 3)!=0;fi++) ; // find flag by name
  if (fi==iflnum) {printf("INTF ERR: %s not found as a flag (%s)\n",sf,iflags); hxe();}
  if (ifarg(2)) {
    if (hoc_is_double_arg(2)) {  // either set to all or just to this one
      val=(unsigned char)*getarg(2);
      if (slowset) { // set one and come back
        printf("NOT IMPLEMENTED\n"); // ****NOT IMPLEMENTED****
      } else if (setfl) { // set them all
        for (ix=0;ix<cesz;ix++) { lop(ce,ix); (&qp->type)[fi]=val; }
      } else {  // just set this one
        (&ip->type)[fi]=((fi>=iflneg)?(char)val:val);
      }
    } else {
      nx=vector_arg_px(2,&x);
      if (nx!=cesz) {
        if (setfl) { printf("INTF flag ERR: vec sz mismatch: %d %d\n",nx,cesz); hxe();
        } else       x=vector_newsize(vector_arg(2),cesz);
      }
      if (setfl && slowset) { // set one and come back
        ix=0;
        lop(ce,ix);
        (&qp->type)[fi]=((fi>=iflneg)?(char)x[ix]:(unsigned char)x[ix]);
        ix++;
        #if defined(t)
        net_send((void**)0x0, wts,tpnt,t+delt,OK); // OK is flag() flag
        #else
        net_send((void**)0x0, wts,tpnt,delt,OK);
        #endif
      } else for (ix=0;ix<cesz;ix++) { 
        lop(ce,ix); 
        if (setfl) { (&qp->type)[fi]=((fi>=iflneg)?(char)x[ix]:(unsigned char)x[ix]);
        } else {
          x[ix]=(double)((fi>=iflneg)?(char)(&qp->type)[fi]:(unsigned char)(&qp->type)[fi]);
        }
      }
    }
  }
  _lflag=(double)((fi>=iflneg)?(char)(&ip->type)[fi]:(unsigned char)(&ip->type)[fi]);
 
return _lflag;
 }
 
static double _hoc_flag(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  flag (  );
 return(_r);
}
 
double allspck (  ) {
   double _lallspck;
 
/*VERBATIM*/
  int i; double *x, sum; void *voi;
  ip = IDP;
  voi=vector_arg(1);  x=vector_newsize(voi,cesz);
  for (i=0,sum=0;i<cesz;i++) { lop(ce,i); 
    x[i]=spck;
    sum+=spck;
  }
  _lallspck=sum;
 
return _lallspck;
 }
 
static double _hoc_allspck(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  allspck (  );
 return(_r);
}
 
static int  resetall (  ) {
   
/*VERBATIM*/
  int ii,i; unsigned char val;
  for (i=0;i<cesz;i++) { 
    lop(ce,i);
    Vm=RMP; VAM=0; VNM=0; VGA=0; VGB=0; VGBa=0; offsetGB=0; AHP=0; rebob=-1e9; invlt=-1; 
    t0=t; tGB=t; trrs=t; twg = t; cbur=0; spck=0; refractory=0; VTHC=VTHR=VTH; 
  }
  return 0; }
 
static double _hoc_resetall(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 resetall (  );
 return(_r);
}
 
double floc (  ) {
   double _lfloc;
 
/*VERBATIM*/
  double x,y,z,r,min,rad, *ix; int ii,i,n,cnt; void* voi;
  cnt=0; n=1000; r=-1;
  ip = IDP;
  x = *getarg(1);
  y = *getarg(2);
  z= ifarg(3)?(*getarg(3)):1e9;
  if (ifarg(5)) {
    r= *getarg(4);
    voi=vector_arg(5);
    ix=vector_newsize(voi,n);
  } 
  for (i=0,min=1e9,ii=-1;i<cesz;i++) { 
    lop(ce,i); 
    rad=(x-xloc)*(x-xloc)+(y-yloc)*(y-yloc)+(z==1e9?0.:((z-zloc)*(z-zloc))); // rad^2
    if (r>0 && rad<r*r) {
      if (cnt>=n) ix=vector_newsize(voi,n*=2);
      ix[cnt]=(double)i;
      cnt++;
    }
    if (rad<min) { min=rad; ii=i; }
  }
  if (r>0) ix=vector_newsize(voi,cnt);
  _lfloc=(double)ii;
 
return _lfloc;
 }
 
static double _hoc_floc(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  floc (  );
 return(_r);
}
 
double invlset (  ) {
   double _linvlset;
 
/*VERBATIM*/
  ip=IDP;
  if (ifarg(1)) ip->invl0 = (unsigned char) *getarg(1);
  _linvlset=(double)ip->invl0;
 
return _linvlset;
 }
 
static double _hoc_invlset(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  invlset (  );
 return(_r);
}
 
double vinset (  ) {
   double _lvinset;
 
/*VERBATIM*/
  ip=IDP;
  if (ifarg(1)) ip->vinflg = (unsigned char) *getarg(1);
  if (ip->vinflg==1) {
    ip->input=1;
    ip->rvi = ip->rvb;
  }
  _lvinset=(double)ip->vinflg;
 
return _lvinset;
 }
 
static double _hoc_vinset(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  vinset (  );
 return(_r);
}
 static double _mfac_EXPo, _tmin_EXPo;
 static void _check_EXPo();
 static void _check_EXPo() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  if (!usetable) {return;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_EXPo =  - 20.0 ;
   _tmax =  0.0 ;
   _dx = (_tmax - _tmin_EXPo)/5000.; _mfac_EXPo = 1./_dx;
   for (_i=0, _x=_tmin_EXPo; _i < 5001; _x += _dx, _i++) {
    _f_EXPo(_x);
    _t_RES[_i] = RES;
   }
  }
 }

 static int EXPo(double _lx){ _check_EXPo();
 _n_EXPo(_lx);
 return 0;
 }

 static void _n_EXPo(double _lx){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_EXPo(_lx); return; 
}
 _xi = _mfac_EXPo * (_lx - _tmin_EXPo);
 if (isnan(_xi)) {
  RES = _xi;
  return;
 }
 if (_xi <= 0.) {
 RES = _t_RES[0];
 return; }
 if (_xi >= 5000.) {
 RES = _t_RES[5000];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 RES = _t_RES[_i] + _theta*(_t_RES[_i+1] - _t_RES[_i]);
 }

 
static int  _f_EXPo (  double _lx ) {
   RES = exp ( _lx ) ;
    return 0; }
 
static double _hoc_EXPo(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
  _r = 1.;
 EXPo (  *getarg(1) );
 return(_r);
}
 
double EXP (  double _lx ) {
   double _lEXP;
 EXPo ( _threadargscomma_ _lx ) ;
   _lEXP = RES ;
   
return _lEXP;
 }
 
static double _hoc_EXP(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  EXP (  *getarg(1) );
 return(_r);
}
 
double esinr (  double _lx ) {
   double _lesinr;
 ESINo ( _threadargscomma_ PI * _lx / tauGB ) ;
   if ( _lx < tauGB ) {
     _lesinr = ( VGBa - offsetGB ) * ESIN + offsetGB ;
     }
   else if ( _lx > 2.0 * tauGB ) {
     _lesinr = 0.0 ;
     }
   else {
     _lesinr = rebound * VGBa * ESIN ;
     }
   
return _lesinr;
 }
 
static double _hoc_esinr(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  esinr (  *getarg(1) );
 return(_r);
}
 static double _mfac_ESINo, _tmin_ESINo;
 static void _check_ESINo();
 static void _check_ESINo() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  if (!usetable) {return;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_ESINo =  0.0 ;
   _tmax =  2.0 * PI ;
   _dx = (_tmax - _tmin_ESINo)/3000.; _mfac_ESINo = 1./_dx;
   for (_i=0, _x=_tmin_ESINo; _i < 3001; _x += _dx, _i++) {
    _f_ESINo(_x);
    _t_ESIN[_i] = ESIN;
   }
  }
 }

 static int ESINo(double _lx){ _check_ESINo();
 _n_ESINo(_lx);
 return 0;
 }

 static void _n_ESINo(double _lx){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_ESINo(_lx); return; 
}
 _xi = _mfac_ESINo * (_lx - _tmin_ESINo);
 if (isnan(_xi)) {
  ESIN = _xi;
  return;
 }
 if (_xi <= 0.) {
 ESIN = _t_ESIN[0];
 return; }
 if (_xi >= 3000.) {
 ESIN = _t_ESIN[3000];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 ESIN = _t_ESIN[_i] + _theta*(_t_ESIN[_i+1] - _t_ESIN[_i]);
 }

 
static int  _f_ESINo (  double _lx ) {
   ESIN = sin ( _lx ) ;
    return 0; }
 
static double _hoc_ESINo(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
  _r = 1.;
 ESINo (  *getarg(1) );
 return(_r);
}
 static double _mfac_rates, _tmin_rates;
 static void _check_rates();
 static void _check_rates() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_mg;
  if (!usetable) {return;}
  if (_sav_mg != mg) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rates =  - 100.0 ;
   _tmax =  50.0 ;
   _dx = (_tmax - _tmin_rates)/300.; _mfac_rates = 1./_dx;
   for (_i=0, _x=_tmin_rates; _i < 301; _x += _dx, _i++) {
    _f_rates(_x);
    _t_Bb[_i] = Bb;
   }
   _sav_mg = mg;
  }
 }

 static int rates(double _lvv){ _check_rates();
 _n_rates(_lvv);
 return 0;
 }

 static void _n_rates(double _lvv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_rates(_lvv); return; 
}
 _xi = _mfac_rates * (_lvv - _tmin_rates);
 if (isnan(_xi)) {
  Bb = _xi;
  return;
 }
 if (_xi <= 0.) {
 Bb = _t_Bb[0];
 return; }
 if (_xi >= 300.) {
 Bb = _t_Bb[300];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 Bb = _t_Bb[_i] + _theta*(_t_Bb[_i+1] - _t_Bb[_i]);
 }

 
static int  _f_rates (  double _lvv ) {
   Bb = 1.0 / ( 1.0 + exp ( 0.062 * - _lvv ) * ( mg / 3.57 ) ) ;
    return 0; }
 
static double _hoc_rates(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
  _r = 1.;
 rates (  *getarg(1) );
 return(_r);
}
 static double _mfac_coop, _tmin_coop;
 static void _check_coop();
 static void _check_coop() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_GPkd;
  if (!usetable) {return;}
  if (_sav_GPkd != GPkd) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_coop =  0.0 ;
   _tmax =  10.0 ;
   _dx = (_tmax - _tmin_coop)/100.; _mfac_coop = 1./_dx;
   for (_i=0, _x=_tmin_coop; _i < 101; _x += _dx, _i++) {
    _f_coop(_x);
    _t_Gn[_i] = Gn;
   }
   _sav_GPkd = GPkd;
  }
 }

 static int coop(double _lx){ _check_coop();
 _n_coop(_lx);
 return 0;
 }

 static void _n_coop(double _lx){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_coop(_lx); return; 
}
 _xi = _mfac_coop * (_lx - _tmin_coop);
 if (isnan(_xi)) {
  Gn = _xi;
  return;
 }
 if (_xi <= 0.) {
 Gn = _t_Gn[0];
 return; }
 if (_xi >= 100.) {
 Gn = _t_Gn[100];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 Gn = _t_Gn[_i] + _theta*(_t_Gn[_i+1] - _t_Gn[_i]);
 }

 
static int  _f_coop (  double _lx ) {
   Gn = ( pow( _lx , 4.0 ) ) / ( pow( _lx , 4.0 ) + GPkd ) ;
    return 0; }
 
static double _hoc_coop(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
  _r = 1.;
 coop (  *getarg(1) );
 return(_r);
}
 
static void _constructor(Prop* _prop) {
	_p = _prop->param; _ppvar = _prop->dparam;
{
 {
   
/*VERBATIM*/

  { int lid,lty,lin,lco,i; unsigned int sz;
    if (ifarg(1)) { lid=(int) *getarg(1); } else { lid= UINT_MAX; }
    if (ifarg(2)) { lty=(int) *getarg(2); } else { lty= -1; }
    if (ifarg(3)) { lin=(int) *getarg(3); } else { lin= -1; }
    if (ifarg(4)) { lco=(int) *getarg(4); } else { lco= -1; }
    _p_sop = (void*)ecalloc(1, sizeof(id0)); // important that calloc sets all flags etc to 0
    ip = IDP;
    ip->id=lid; ip->type=lty; ip->inhib=lin; ip->col=lco; 
    ip->pg=0x0; ip->dvi=0x0; ip->sprob=0x0;
    ip->dead = ip->invl0 = ip->record = ip->jttr = ip->input = 0; // all flags off
    ip->dvt = ip->vbr = ip->wrec = ip->jcn = 0;
    for (i=0;i<WRNUM;i++) {ip->wreci[i]=-1; ip->wscale[i]=-1.0;}
    ip->rve=-1;
    pathbeg=-1;
    slowset=jrmax=0; 
    process=(int)getpid();
    CNAME[SU]="SU"; CNAME[DP]="DP"; CNAME[IN]="IN";
    if (installed==2.0) { // jitcondiv was previously run
      sz=ivoc_list_count(ce);
      printf("\t**** WARNING new INTF created: may want to rerun jitcondiv ****\n");
    } else installed=1.0; // set or reset it
    cbsv=0x0;
  }
 }
 
}
}
 
static void _destructor(Prop* _prop) {
	_p = _prop->param; _ppvar = _prop->dparam;
{
 {
   
/*VERBATIM*/
{ 
  free(IDP);
  }
 }
 
}
}

static void initmodel() {
  int _i; double _save;_ninits++;
{
 {
   double _lid ;
 reset ( _threadargs_ ) ;
   t0 = 0.0 ;
   tg = 0.0 ;
   twg = 0.0 ;
   tGB = 0.0 ;
   trrs = 0.0 ;
   tmax = 0.0 ;
   pathend = - 1.0 ;
   pathlen = 0.0 ;
   spck = 0.0 ;
   
/*VERBATIM*/
  { int i,ix;
  ip=IDP;
  _lid=(double)ip->id;
  ip->spkcnt=0;
  ip->blkcnt=0;
  ip->errflag=0;
  for (i=0;i<CTYN;i++){ix=cty[i]; blockcnt[ix]=spikes[ix]=AMo[ix]=NMo[ix]=GAo[ix]=GBo[ix]=0;}
  }
 jrsvn = jrsvd ;
   jrtime = jrtm ;
   if ( vinflag ( _threadargs_ ) ) {
     randspk ( _threadargs_ ) ;
     artcell_net_send ( _tqitem, (double*)0, _ppvar[1]._pvoid, t +  nxt , 2.0 ) ;
     }
   if ( recflag ( _threadargs_ ) ) {
     recini ( _threadargs_ ) ;
     }
   if ( pathbeg  == _lid ) {
     stoprun = 0.0 ;
     artcell_net_send ( _tqitem, (double*)0, _ppvar[1]._pvoid, t +  0.0 , 2.0 ) ;
     }
   rebeg = 0.0 ;
   }

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
 _tsav = -1e20;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
} return _current;
}

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
 _break = t + .5*dt; _save = t;
 v=_v;
{
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
   _t_Psk = makevector(82*sizeof(double));
   _t_RES = makevector(5001*sizeof(double));
   _t_ESIN = makevector(3001*sizeof(double));
   _t_Bb = makevector(301*sizeof(double));
   _t_Gn = makevector(101*sizeof(double));
_first = 0;
}
