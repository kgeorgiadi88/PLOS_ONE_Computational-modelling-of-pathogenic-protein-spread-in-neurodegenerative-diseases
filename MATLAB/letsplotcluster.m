close all; clear variables; clc;
savepdf = 1;
for hide = 1:1
    E2 = 18; E2B = 19; I2 = 20; I2L = 23; E4 = 15; I4 = 16; I4L = 17; E5B = 11; E5R = 12; I5 = 13;
    I5L = 14; E6 = 7; I6 = 8; I6L = 10;
    t.E2 = 18; t.E2B = 19; t.I2 = 20; t.I2L = 23; t.E4 = 15; t.I4 = 16; t.I4L = 17; t.E5B = 11; t.E5R = 12;
    t.I5 = 13; t.I5L = 14; t.E6 = 7; t.I6 = 8; t.I6L = 10;
    NumTypePerColumn = zeros(40,1);
    NumTypePerColumn(t.E2) = 142;
    NumTypePerColumn(t.E2B) = 8;
    NumTypePerColumn(t.I2) = 25;
    NumTypePerColumn(t.I2L) = 13;
    NumTypePerColumn(t.E4) = 30;
    NumTypePerColumn(t.I4) = 20;
    NumTypePerColumn(t.I4L) = 14;
    NumTypePerColumn(t.E5B) = 17;
    NumTypePerColumn(t.E5R) = 65;
    NumTypePerColumn(t.I5) = 25;
    NumTypePerColumn(t.I5L) = 13;
    NumTypePerColumn(t.E6) = 60;
    NumTypePerColumn(t.I6) = 25;
    NumTypePerColumn(t.I6L) = 13;
end
[Load_Directories, Save_Directories, ~, ~] = GetInputFoldersCluster;

CurrentLoadDirectory = pwd;
CurrentLoadDirectory = [CurrentLoadDirectory '/'];

for CurrentExperiment = 1:numel(Load_Directories)
    if(strcmp(CurrentLoadDirectory, Load_Directories{CurrentExperiment}) == 1)
        break;
    end
end

CurrentLoadDirectory = Load_Directories{CurrentExperiment};
CurrentSaveDirectory = Save_Directories{CurrentExperiment};
mkdir(CurrentSaveDirectory);

dlmwrite([CurrentLoadDirectory 'PlotFinished.dat'], 0);

SimulationFinished = dlmread('Finished.dat');
if(SimulationFinished ~= 1)
    fprintf('\n\n!!!!!\nREAD ERROR. Simulation never finished!!!!!!!\n!!!!!\n\n');
    exit;
end

fprintf('Experiment %d Metrics\n', CurrentExperiment);
PlotMetrics( CurrentLoadDirectory, CurrentSaveDirectory, savepdf);
fprintf('Experiment %d Death Times\n', CurrentExperiment);
PlotDeathTimes( CurrentLoadDirectory, CurrentSaveDirectory, savepdf);
fprintf('Experiment %d Frequencies\n', CurrentExperiment);
PlotFrequencies( CurrentLoadDirectory, CurrentSaveDirectory, savepdf, t, NumTypePerColumn);
fprintf('Experiment %d Damage\n', CurrentExperiment);
PlotDamage( CurrentLoadDirectory, CurrentSaveDirectory, savepdf);
fprintf('Experiment %d All Concentrations\n', CurrentExperiment);
PlotAllConcentrations( CurrentLoadDirectory, CurrentSaveDirectory, savepdf);
fprintf('Experiment %d Uniformity\n', CurrentExperiment);
PlotGradientVsUniformCluster( CurrentLoadDirectory, CurrentSaveDirectory,savepdf );
fprintf('Experiment %d Copying convergence data\n', CurrentExperiment);
CopyConvergence( CurrentLoadDirectory, CurrentSaveDirectory,savepdf );

dlmwrite([CurrentLoadDirectory 'PlotFinished.dat'], 1);

close all;
exit;
