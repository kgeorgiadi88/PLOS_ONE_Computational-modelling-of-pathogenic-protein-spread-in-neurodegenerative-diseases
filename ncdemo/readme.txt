 $Id: readme.txt,v 1.2 2010/11/01 13:45:41 samn Exp $ 

--------------------------------------------------------------------------
                           Neocortical Column Demo Readme
--------------------------------------------------------------------------

This package contains the source code from the paper:
  Synaptic information transfer in computer models of neocortical columns.
  Article by SA Neymotin, KM Jacobs, AA Fenton, and WW Lytton
  Journal of Computational Neuroscience (2010), in press.
  PubMed ID 20556639.

It allows simulating the activity of a neocortical column using
conductance- based neurons. In addition, NEURON vector implementations
of normalized transfer entropy are provided in infot.mod. For more
information on methods used, please see the paper.

--------------------------------------------------------------------------
                      Compilation/running instructions (LINUX)
--------------------------------------------------------------------------

You will need the NEURON simulator in order to run this simulation.
It is available for download at http://www.neuron.yale.edu/neuron/
Detailed installation instructions are available there as well.

Once you have NEURON installed you will need to compile the .mod files
included in the zip file. To do so first extract the contents of the
zip file into a single flat directory.

If you are on LINUX/UNIX then run nrnivmodl *.mod from the command
line to compile the .mod files. If this is done properly, an
executable named 'special' will be produced in the x86_64 subdirectory
(on 64 bit machines) or x86 subdirectory on 32 bit machines.

(If you are using WINDOWS this is not guaranteed to work but try the
instructions at:
http://www.neuron.yale.edu/neuron/docs/nmodl/mswin.html for more
information on compiling new mechanisms into NEURON .)

Next, to run the simulation enter the following command at the command
prompt:
  ./x86_64/special (or ./x86/special )

This will begin the NEURON simulator.  You will then be at the NEURON
command prompt which should look like this: oc> Type
load_file("mosinit.hoc") and press enter.  This will start the
neocortical column simulation.  A GUI window will be displayed that
will allow running the simulation and displaying output consisting of:

 1. spike raster
 2. local field potential
 3. voltage of several cells with different dynamical properties

--------------------------------------------------------------------------
                              Contact
--------------------------------------------------------------------------

For questions/comments/collaborations please contact 
Samuel Neymotin at samn at neurosim dot downstate dot edu
     or
Bill Lytton at billl at neurosim dot downstate dot edu
