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
#define pointer _p[0]
#define _nd_area  *_ppvar[0]._pval
 
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
 /* declaration of user functions */
 static double _hoc_datavec();
 static double _hoc_get_adcunit();
 static double _hoc_get_cpulse();
 static double _hoc_get_label();
 static double _hoc_get_comment();
 static double _hoc_gain();
 static double _hoc_parm();
 static double _hoc_timestep();
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
 "datavec", _hoc_datavec,
 "get_adcunit", _hoc_get_adcunit,
 "get_cpulse", _hoc_get_cpulse,
 "get_label", _hoc_get_label,
 "get_comment", _hoc_get_comment,
 "gain", _hoc_gain,
 "parm", _hoc_parm,
 "timestep", _hoc_timestep,
 0, 0
};
#define gain gain_ClampExData
#define parm parm_ClampExData
#define timestep timestep_ClampExData
 extern double gain( );
 extern double parm( );
 extern double timestep( );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
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
"ClampExData",
 0,
 0,
 0,
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
 	_p = nrn_prop_data_alloc(_mechtype, 1, _prop);
 	/*initialize range parameters*/
  }
 	_prop->param = _p;
 	_prop->param_size = 1;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 if (!nrn_point_prop_) {_constructor(_prop);}
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _clampex_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,(void*)0, (void*)0, (void*)0, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 	register_destructor(_destructor);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
  hoc_register_prop_size(_mechtype, 1, 2);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ClampExData /home/konstantinos/Desktop/NEURON/ncdemo/x86_64/clampex.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int datavec();
static int get_adcunit();
static int get_cpulse();
static int get_label();
static int get_comment();
 
/*VERBATIM*/
extern double chkarg();

typedef struct CEXData {
#if 1
	char header[1024];
#else
	float parm_[80];
	char comment_[77];
	char labels[5][16];
	char reserve1[35];
	char cond_pulse[64];
	long parm_extension[16];
	float adc_ext_offset[16];
	float adc_ext_gain[16];
	float adc_disp_amp[16];
	float adc_disp_offset[16];
	char  adc_units[16][8];
#endif
	short* data;
}CEXData;
#define CEXD CEXData* cexd = (CEXData*)((unsigned long)pointer);
	
static void reverse(b, n ) char* b; int n; {
	int i, j, v_;
	for (i=0, j=n-1; i<j; ++i, --j) {
		v_ = b[i];
		b[i] = b[j];
		b[j] = v_;
	}
}

static void header_endian(h) char* h; {
	char* b;
	int i;
	b = h;
	for (i=0; i < 80; ++i) {/* parameters */
		reverse(b, 4);
		b += 4;
	}
	b += (77 + 80 + 35 + 64);
	for (i=0; i < 16; ++i) {/* parameter extension */
		reverse(b, 4);
		b += 4;
	}
	for (i=0; i < 64; ++i) {
		reverse(b, 4);
		b += 4;
	}
}

static double get_parm(i, h) int i; char* h; {
	char* b;
	float* f;
	long* n;
	b = h;
	if (i <= 80) {
		f = (float*)b;
		return (double)f[i-1];
	}
	b += 320 + 77 + 80 + 35 + 64;
	if (i <= 96) {
		f = (float*)b;
		return (double)f[i- 81];
	}
	b += 64;
	if (i <= 160) {
		f = (float*)b;
		return (double)f[i - 97];
	}
	return 0.;
}
		
 
double parm (  ) {
   double _lparm;
 
/*VERBATIM*/
	CEXD
	int i;
	i = (int)chkarg(1, 1., 160.);
	_lparm = get_parm(i, cexd->header);
 
return _lparm;
 }
 
static double _hoc_parm(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  parm (  );
 return(_r);
}
 
static int  datavec (  ) {
   
/*VERBATIM*/
	int ntrace, trace, i, length;
	double* pd, *hoc_pgetarg();
	short* tr;
	CEXD
	length = (int)get_parm(3, cexd->header);
	ntrace = (int)get_parm(4, cexd->header);
	trace = (int)chkarg(1, 0., (double)(ntrace - 1));
	tr = cexd->data + length*trace;
	pd = hoc_pgetarg(2);
	for (i = 0; i < length; ++i) {
		pd[i] = (double)tr[i];
	}
  return 0; }
 
static double _hoc_datavec(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 datavec (  );
 return(_r);
}
 
double timestep (  ) {
   double _ltimestep;
 
/*VERBATIM*/
	CEXD
	_ltimestep = get_parm(14, cexd->header)*.001;
 
return _ltimestep;
 }
 
static double _hoc_timestep(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  timestep (  );
 return(_r);
}
 
double gain (  ) {
   double _lgain;
 
/*VERBATIM*/
	CEXD
	_lgain = get_parm(113, cexd->header);
 
return _lgain;
 }
 
static double _hoc_gain(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  gain (  );
 return(_r);
}
 
static int  get_comment (  ) {
   
/*VERBATIM*/
	char buf[80];
	CEXD
	strncpy(buf, cexd->header + 320, 77);
	buf[77] = '\0';
	printf("%s\n", buf);
  return 0; }
 
static double _hoc_get_comment(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 get_comment (  );
 return(_r);
}
 
static int  get_label (  ) {
   
/*VERBATIM*/
	char buf[80];
	CEXD
	int i = (int)chkarg(1, 1., 5.);
	strncpy(buf, cexd->header + (320 + 77  +(i-1)*16), 16);
	buf[16] = '\0';
	printf("%s\n", buf);
  return 0; }
 
static double _hoc_get_label(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 get_label (  );
 return(_r);
}
 
static int  get_cpulse (  ) {
   
/*VERBATIM*/
	char buf[80];
	CEXD
	strncpy(buf, cexd->header + 320 + 77 + 80 + 35, 64);
	buf[64] = '\0';
	printf("%s\n", buf);
  return 0; }
 
static double _hoc_get_cpulse(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 get_cpulse (  );
 return(_r);
}
 
static int  get_adcunit (  ) {
   
/*VERBATIM*/
	char buf[80];
	CEXD
	int i = (int)chkarg(1, 1., 16.);
	strncpy(buf, cexd->header + (320 + 77 + 80 + 35 + 6*64 + (i-1)*8), 8);
	buf[8] = '\0';
	printf("%s\n", buf);
  return 0; }
 
static double _hoc_get_adcunit(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 get_adcunit (  );
 return(_r);
}
 
static void _constructor(Prop* _prop) {
	_p = _prop->param; _ppvar = _prop->dparam;
{
 {
   
/*VERBATIM*/

	FILE* fin;
	int endian = 0;
	int samples, episodes;
	CEXData* cexd;
	char* fname;
	fname = gargstr(2);
//	printf("fname = %s\n", fname);
	fin = fopen(fname, "rb");
	if (!fin) {
		printf("can't open %s for reading\n", fname);
	}
	cexd = (CEXData*)emalloc(sizeof(CEXData));
	pointer = (double) ((unsigned long)cexd);
	fread(cexd->header, 1024, 1, fin);
	cexd->data = 0;
	if (get_parm(1, cexd->header) != 1.) {
		header_endian(cexd->header);
		endian = 1;
	}
	if (get_parm(1, cexd->header) != 1.) {
		printf("%s is not a CLAMPEX file\n", fname);
	}
	samples = (int)get_parm(3, cexd->header);
	episodes = (int)get_parm(4, cexd->header);
	cexd->data = (short*)emalloc(samples*episodes*sizeof(short));
	fread(cexd->data, samples*episodes, sizeof(short), fin);
	fclose(fin);
	if (endian) {
		int i;
		for (i=0; i < samples*episodes; ++i) {
			reverse((char*)(cexd->data + i), 2);
		}
	}
 }
 
}
}
 
static void _destructor(Prop* _prop) {
	_p = _prop->param; _ppvar = _prop->dparam;
{
 {
   
/*VERBATIM*/
	CEXD
	if (cexd->data) {
		free(cexd->data);
	}
	free(cexd);
 }
 
}
}

static void initmodel() {
  int _i; double _save;_ninits++;
{

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
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}
