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
 static void _hoc_install_updown(void);
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
 "setdata_updown", _hoc_setdata,
 "install_updown", _hoc_install_updown,
 0, 0
};
 /* declare global and static user variables */
 double CREEP_UPDOWN = 0;
 double DEBUG_UPDOWN = 0;
 double NOV_UPDOWN = 1;
 double SHM_UPDOWN = 4;
 double UPDOWN_INSTALLED = 0;
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
 "UPDOWN_INSTALLED", &UPDOWN_INSTALLED,
 "DEBUG_UPDOWN", &DEBUG_UPDOWN,
 "SHM_UPDOWN", &SHM_UPDOWN,
 "NOV_UPDOWN", &NOV_UPDOWN,
 "CREEP_UPDOWN", &CREEP_UPDOWN,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "6.2.0",
"updown",
 0,
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 0, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 0;
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*f)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _updown_reg() {
	int _vectorized = 0;
  _initlists();
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 updown /home/konstantinos/Desktop/NEURON/ncdemo/x86_64/updown.mod\n");
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int install_updown();
 
/*VERBATIM*/
#include <stdlib.h>
#include <math.h>
#include <limits.h> // contains LONG_MAX 
#include <sys/time.h> 
extern double* hoc_pgetarg();
extern double hoc_call_func(Symbol*, int narg);
extern FILE* hoc_obj_file_arg(int narg);
extern Object** hoc_objgetarg();
extern void vector_resize();
extern int vector_instance_px();
extern void* vector_arg();
extern double* vector_vec();
extern double hoc_epsilon;
extern double chkarg();
extern void set_seed();
extern int ivoc_list_count(Object*);
extern Object* ivoc_list_item(Object*, int);
extern int hoc_is_double_arg(int narg);
extern char* hoc_object_name(Object*);
char ** hoc_pgargstr();
int list_vector_px();
int list_vector_px2();
int list_vector_px3();
double *list_vector_resize();
int ismono1();
static void hxe() { hoc_execerror("",0); }
static void hxf(void *ptr) { free(ptr); hoc_execerror("",0); }
 
/*VERBATIM*/

  //** declarations
#define UDSL 500
#define UDNQ 11
// nq=new NQS("LOC","PEAK","WIDTH","BASE","HEIGHT","START","SLICES","SHARP","INDEX","FILE","NESTED")
#define LOC     nq[0] // loc of peak of spike
#define PEAK  	nq[1] // value at peak (absolute height)
#define WIDTH  	nq[2] // rt flank - lt flanks (? isn't it rt flank - LOC ?)
#define BASE  	nq[3] // height at base
#define HEIGHT  nq[4] // peak - base
#define START  	nq[5] // left flank of spike?
#define SLICES  nq[6] // how many slices found this spike
#define SHARP  	nq[7] // 2nd deriv at peak
#define INDEX  	nq[8] // consecutive numbering of spikes
//        	nq[9] // will use to fill in trace's file name at hoc level
#define NESTED  nq[10] // how many bumps are nested within this one
  //** procedure updown()
static double updown (void* vv) {
  int i, k, m, n, nqsz, nsrc, jj[UDSL], f[UDSL], lc, dsz[UDSL], nqmax, thsz, lc2, done, dbn;
  double *src, *tvec, *th, *dest[UDSL], *nq[UDNQ], *tmp, *dbx, lt, thdist;
  Object *ob, *ob2;
  void *vvd[UDSL], *vvth, *vnq[UDNQ];
  //** read in vectors and verify sizes, etc
  nsrc = vector_instance_px(vv, &src); // trace to analyze
  thsz = vector_arg_px(1, &th);        // vector of thresholds to check
  ob =  *hoc_objgetarg(2);             // storage for values for each threshold
  ob2 = *hoc_objgetarg(3);             // list of NQS vectors for returning values
  tmp = (double *)ecalloc(nsrc, sizeof(double));  // tmp is size of trace
  lc =  ivoc_list_count(ob);
  lc2 = ivoc_list_count(ob2);
  if (lc>UDSL) {printf("updown ERRF mismatch: max slice list:%d %d\n",UDSL,lc); hxf(tmp);}
  if (lc2!=UDNQ){printf("updown ERRB mismatch: NQS sz is %d (%d in list)\n",UDNQ,lc2);hxf(tmp);}
  if (nsrc<lc) {printf("updown ERRC mismatch: %d %d\n",lc,nsrc); hxf(tmp);} // ??
  if (lc!=thsz) {printf("updown ERRA mismatch: %d %d\n",lc,thsz); hxf(tmp);}
  if (!ismono1(th,thsz,-1)) {printf("updown ERRD: not mono dec %g %d\n",th[0],thsz); hxf(tmp);}
  // thdist=(th[thsz-2]-th[thsz-1])/2; // NOT BEING USED: the smallest spike we will accept
  for (k=0;k <lc;k++)  dsz[k] =list_vector_px3(ob , k, &dest[k], &vvd[k]);
  for (k=0;k<lc2;k++) {
    i=list_vector_px3(ob2, k, &nq[k],   &vnq[k]);
    if (k==0) nqmax=i; else if (i!=nqmax) { // all NQ vecs same size
      printf("updown ERRE mismatch: %d %d %d\n",k,i,nqmax); hxf(tmp); }
  }
  //** store crossing points and midpoints in dest[k]
  // dest vectors dest[k] will store crossing points and midpoints at each th[k] slice location
  // as triplets: up/max/down
  for (k=0; k<lc; k++) {   // iterate thru thresholds
    jj[k]=f[k]=0; // jj[k] is ind into dest[k]; f[k] is flag for threshold  crossings
    for (i=0;i<nsrc && src[i]>th[k];i++) {} // start somewhere below this thresh th[k]
    for (; i<nsrc; i++) { // iterate through trace
      if (src[i]>th[k]) { 
        if (f[k]==0) { // ? passing thresh 
          if (jj[k]>=dsz[k]){printf("(%d,%d,%d) :: ",k,jj[k],dsz[k]);
            hoc_execerror("Dest vec too small in updown ", 0); }
          dest[k][jj[k]++] = (i-1) + (th[k]-src[i-1])/(src[i]-src[i-1]); // interpolate
          f[k]=1; 
          tmp[k]=-1e9; dest[k][jj[k]]=-1.; // flag in tmp says that a thresh found here
        }
        if (f[k]==1 && src[i]>tmp[k]) { // use tmp[] even more temporarily
          tmp[k]=src[i]; // pick out max
          dest[k][jj[k]] = (double)i; // location of this peak
        }
      } else {          // below thresh 
        if (f[k]==1) {  // just passed going down 
          jj[k]++;      // triplet will be indices of cross-up/peak/cross-down
          dest[k][jj[k]++] = (i-1) + (src[i-1]-th[k])/(src[i-1]-src[i]);
          f[k]=0; 
        }
      }
    }
  }
  //** truncate dest vectors to multiples of 3:
  for (k=0;k<lc;k++) vector_resize(vvd[k],(int)(floor((double)jj[k]/3.)*3.));
  for (i=0; i<nsrc; i++) tmp[i]=0.; // clear temp space
  //** go through all the slices to find identical peaks and save widths and locations
  // tmp[] uses triplets centered around a location corresponding to a max loc in the
  // original vector; the widest flanks for each are then on either side of this loc
  for (k=0;k<lc;k++) { // need to go from top to bottom to widen flanks
    for (i=1;i<jj[k];i+=3) { // through centers (peaks)
      m=(int)dest[k][i]; // hash: place center at location
      if (tmp[m-2]<0 || tmp[m-1]<0 || tmp[m+1]<0 || tmp[m+2]<0) continue; // ignore; too crowded
      tmp[m]--;  // count how many slices have found this peak (use negative)
      tmp[m-1]=dest[k][i-1]; tmp[m+1]=dest[k][i+1]; // flanks
    }
  }
  //** 1st (of 2) loops through tmp[] -- pick up flanks
  // step through tmp[] looking for negatives which indicate the slice count and pick up 
  // flanks from these
  // nq=new NQS("LOC","PEAK","WIDTH","BASE","HEIGHT","START","SLICES","SHARP","INDEX","FILE")
  for (i=0,k=0; i<nsrc; i++) if (tmp[i]<0.) { // tmp holds neg of count of slices
    if (k>=nqmax) { printf("updown ERRG OOR in NQ db: %d %d\n",k,nqmax); hxf(tmp); }
    LOC[k]=(double)i;  // approx location of the peak of the spike
    WIDTH[k]=tmp[i+1]; // location of right side -- temp storage
    START[k]=tmp[i-1]; // start of spike (left side)
    SLICES[k]=-tmp[i];  // # of slices
    k++;
  }
  nqsz=k;   // k ends up as size of NQS db
  if (DEBUG_UPDOWN && ifarg(4)) { dbn=vector_arg_px(4, &dbx); // DEBUG -- save tmp vector
    if (dbn<nsrc) printf("updown ERRH: Insufficient room in debug vec (%d<%d)\n",dbn,nsrc); 
    else for (i=0;i<nsrc;i++) dbx[i]=tmp[i]; 
  }
  //** adjust flanks to handle nested bumps
  // 3 ways to handle spike nested in a spike or elongated base:
  // NB always using same slice for both L and R flanks; NOV_UPDOWN flag: (no-overlap)
  //   0. nested spike(s) share flanks determined by shared base
  //   1. nested spike(s) have individual bases, 1st and last use flanks from base
  //   2. nested spike(s) have individual bases, base flanks listed separately w/out peak
  // here use 
  // search nq vecs to compare flanks to neighboring centers
  // if flanks overlap the centers on LT or RT side,
  // correct them by going back to original slice loc info (in dest[])
  //*** look at left side -- is this flank to left of center of another bump?
  if (NOV_UPDOWN) for (i=0;i<nqsz;i++) { // iterate through NQS db
    if ((i-1)>0 && START[i] < LOC[i-1]) { // flank is to left of prior center
      if (DEBUG_UPDOWN) printf("LT problem %d %g %g<%g\n",i,LOC[i],START[i],LOC[i-1]);
      for (m=lc-1,done=0;m>=0 && !done;m--) { // m:go from bottom (widest) to top
        for (n=1;n<jj[m] && !done;n+=3) {     // n:through centers
          // pick out lowest slice with this peak LOC whose flank is to RT of prior peak
          if (floor(dest[m][n])==LOC[i] && dest[m][n-1]>LOC[i-1]) {
            // ??[i]=START[i]; // temp storage for L end of this overlap
            // replace both left and right flanks at this level -- #1 above
            START[i]=dest[m][n-1]; WIDTH[i]=dest[m][n+1]; done=1; 
          }
        }
      }
    }
    //*** now look at RT side
    if ((i+1)<nqsz && WIDTH[i]>LOC[i+1]) {
      if (DEBUG_UPDOWN) printf("RT problem %d %g %g>%g\n",i,LOC[i],WIDTH[i],LOC[i+1]);
      for (m=lc-1,done=0;m>=0 && !done;m--) { // m: go from bottom to top
        for (n=1;n<jj[m] && !done;n+=3) {     // n: through centers
          // pick out lowest slice with this peak LOC whose flank is to LT of next peak
          if (floor(dest[m][n])==LOC[i] && dest[m][n+1]<LOC[i+1]) {
            // ??[i]=WIDTH[i]; // end of overlap
            START[i]=dest[m][n-1]; WIDTH[i]=dest[m][n+1]; done=1;
          }
        }
      }        
    }
  }

  //make sure left and right sides of bump occur at local minima
  //shouldn't creeping be before NOV_UPDOWN=1 overlap check???
  //creeping can result only in equal borders btwn two bumps
  //on one side, so it should be ok here...
  if(CREEP_UPDOWN) for(i=0,k=0;i<nsrc;i++) if(tmp[i]<0.){

    //move left side to local minima
    int idx = (int)START[k];
    while(idx >= 1 && src[idx] >= src[idx-1]) idx--;
    START[k] = idx;

    //move right side to local minima
    idx = (int)WIDTH[k];
    while(idx < nsrc-1 && src[idx] >= src[idx+1]) idx++;
    WIDTH[k] = idx;

    k++;
  }

  //** 2nd loop through tmp[] used to fill in the rest of NQS
  // needed to split into 2 loops so that could check for overlaps and correct those
  // before filling in the rest of nq
  for (i=0,k=0; i<nsrc; i++) if (tmp[i]<0.) { // tmp holds neg of count of slices
    // calculate a base voltage lt as interpolated value on left side
    lt=src[(int)floor(START[k])]+(START[k]-floor(START[k]))*\
      (src[(int)floor(START[k]+1.)]-src[(int)floor(START[k])]);
    BASE[k]=lt;         // base voltage
    PEAK[k]=src[i];     // peak voltage
    WIDTH[k] = WIDTH[k] - START[k]; // width = RT_flank-LT_flank
    HEIGHT[k]=PEAK[k]-BASE[k]; // redund measure -- can eliminate
    // measure of sharpness diff of 1st derivs btwn peak and SHM_UPDOWN dist from peak
    // to get 2nd deriv would be normalized by 2*SHM_UPDOWN*tstep
    // ??could take an ave. or max first deriv for certain distance on either side
    SHARP[k]=(src[i]-src[i-(int)SHM_UPDOWN])-(src[i+(int)SHM_UPDOWN]-src[i]);
    INDEX[k]=(double)k;
    k++;
  }
  
  int iNumBumps = k;

  //count # of other bumps nested within each bump
  if(!NOV_UPDOWN){
    for(i=0; i<iNumBumps; i++){
      NESTED[i] = 0;
      int j = 0;
      for(;j<iNumBumps;j++){
        if(i!=j && LOC[j] >= START[i] && LOC[j] <= START[i]+WIDTH[i]){
          NESTED[i]+=1.0;
        }
      }
    }
  } else for(i=0;i<iNumBumps;i++) NESTED[i]=0.0;

  //** finish up
  for (i=0;i<lc2;i++) vector_resize(vnq[i], nqsz);
  if (k!=nqsz) { printf("updown ERRI INT ERR: %d %d\n",k,nqsz); hxf(tmp); }
  free(tmp);
  return jj[0];
}


 
static int  install_updown (  ) {
   if ( UPDOWN_INSTALLED  == 1.0 ) {
     printf ( "$Id: updown.mod,v 1.16 2009/02/16 22:56:52 billl Exp $\n" ) ;
     }
   else {
     UPDOWN_INSTALLED = 1.0 ;
     
/*VERBATIM*/
{
  install_vector_method("updown", updown);
  }
 }
    return 0; }
 
static void _hoc_install_updown(void) {
  double _r;
   _r = 1.;
 install_updown (  );
 hoc_retpushx(_r);
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
