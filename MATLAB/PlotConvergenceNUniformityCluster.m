close all; clear variables; clc;
loadmatrix = 1;
savepdf = 1;
Convergence_Threshold = 0.8;
FontSizeAll = 18;
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
[Load_Directories, Save_Directories, VariablesSize, VariablesNames] = GetInputFoldersNew;
Save_Directory = '/Users/kgeorgiadi/Documents/PhD/Results/PNAS2017/Conv/';
mkdir(Save_Directory);

NumVariables = numel(VariablesSize);
CurrentExperimentParameterSet = ones(1,NumVariables);
TotalExperiments = prod(VariablesSize);
zz = zeros(NumVariables, TotalExperiments);

%Prepare Data
for CurrentExperiment = 1:TotalExperiments
    CurrentLoadDirectory = Save_Directories{CurrentExperiment};
    z = CurrentExperimentParameterSet;
    zz(:,CurrentExperiment) = CurrentExperimentParameterSet';
    
    OrderIndices = dlmread([CurrentLoadDirectory 'AtrophyOrderIndices1.dat']);
    UnifValue = dlmread([CurrentLoadDirectory 'GradUnifMeanValue.dat']);
    FlowValue = dlmread([CurrentLoadDirectory 'FlowDiffValue.dat']);
    GeodesicValue = dlmread([CurrentLoadDirectory 'GeodesicDistanceValue.dat']);
    SynapticValue = dlmread([CurrentLoadDirectory 'SynDiffValue.dat']);
    TimeFinished = dlmread([CurrentLoadDirectory 'TimeFinished.dat']);

	EventSequenceVectors(:,CurrentExperiment) = OrderIndices'+1;
    AllUnifValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8)) = UnifValue;
    AllFlowValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8)) = FlowValue;
    AllGeodesicValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8)) = GeodesicValue;
    AllSynapticValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8)) = SynapticValue;
    TimeFinishedValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8)) = TimeFinished;
    if(CurrentExperiment < TotalExperiments)
        k = NumVariables;
        CurrentExperimentParameterSet(k) = CurrentExperimentParameterSet(k) + 1;
        while(1)
            if(CurrentExperimentParameterSet(k) > VariablesSize(k))
                CurrentExperimentParameterSet(k) = 1;
                k = k - 1;
                CurrentExperimentParameterSet(k) = CurrentExperimentParameterSet(k) + 1;
            else
                break;
            end
        end
    end
end

save([Save_Directory 'AllUnifValues.mat'], 'AllUnifValues');
save([Save_Directory 'AllFlowValues.mat'], 'AllFlowValues');
save([Save_Directory 'AllGeodesicValues.mat'], 'AllGeodesicValues');
save([Save_Directory 'AllSynapticValues.mat'], 'AllSynapticValues');
save([Save_Directory 'TimeFinishedValues.mat'], 'TimeFinishedValues');


%%

NumEvents = size(EventSequenceVectors,1);
ConvergenceMinMatrix = zeros(TotalExperiments);
if(loadmatrix == 0)
    for experiment1 = 1:TotalExperiments
        experiment1/TotalExperiments
        for experiment2 = (experiment1+1):TotalExperiments
            if(EventSequenceVectors(1,experiment1) == 0 || EventSequenceVectors(1,experiment2) == 0)
                ConvergenceVector = zeros(NumEvents,1);
            else
                A1 = false(NumEvents,1);
                A2 = false(NumEvents,1);
                SumVar = 0;
                for i = 1:NumEvents
                    A1(EventSequenceVectors(i,experiment1)) = true;
                    SumVar = SumVar + A2(EventSequenceVectors(i,experiment1));
                    A2(EventSequenceVectors(i,experiment2)) = true;
                    SumVar = SumVar + A1(EventSequenceVectors(i,experiment2));
                    ConvergenceVector(i,1) = SumVar/i;
                end
            end
            
            
            %Min is best
            MovingMin = zeros(NumEvents,1);
            minval = 10;
            for i = NumEvents:-1:1
                if(ConvergenceVector(i) < minval)
                    minval = ConvergenceVector(i);
                end
                MovingMin(i) = minval;
            end
            for i = 1:NumEvents
                if(MovingMin(i) >= Convergence_Threshold)
                    EarliestConvergence = i;
                    break;
                end
            end
            ConvergenceMinMatrix(experiment1, experiment2) = EarliestConvergence;
            ConvergenceMinMatrix(experiment2, experiment1) = EarliestConvergence;
            
        end
    end
    ConvergenceMinMatrix = ConvergenceMinMatrix/NumEvents;
end

if(loadmatrix == 1)
    load([Save_Directory 'ConvergenceMatrix10000x10000.mat']);
end

close all;
width = 30;
height = 30;
h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
	'PaperUnits','centimeters',...
	'PaperSize',[width height],...
	'PaperPositionMode','auto',...
	'InvertHardcopy', 'on',...
	'Renderer','painters'...
	);
imagesc(ConvergenceMinMatrix);
% for i = 0:16:prod(AllNumbers); line(xlim+[-7 0],[1,1]*i + 0.5,'color','k','LineWidth',2,'Clipping','off');  end
% for i = 0:16:prod(AllNumbers); line([1,1]*i + 0.5,ylim+[0 5],'color','k','LineWidth',2,'Clipping','off');  end
% for i = 0:3*16:prod(AllNumbers); line(xlim+[-12 0],[1,1]*i + 0.5,'color','k','LineWidth',4,'Clipping','off');  end
% for i = 0:3*16:prod(AllNumbers); line([1,1]*i + 0.5,ylim+[0 10],'color','k','LineWidth',4,'Clipping','off');  end
set(gca,'FontSize',FontSizeAll)
title(['Convergence measured by the earliest timestep that the dice score remained >' num2str(Convergence_Threshold)],'FontSize',FontSizeAll)

% i = prod(AllNumbers)+5; line(xlim+[-0 0],[1,1]*i + 0.5,'color','k','LineWidth',2,'Clipping','off'); 
% i = -7; line([1,1]*i + 0.5,ylim+[0 0],'color','k','LineWidth',2,'Clipping','off');
% 
% t0 = text(-4,15+16*0,'f_{inter}=1','FontSize',14);
% t1 = text(-4,15+16*1,'f_{inter}=10','FontSize',14);
% t2 = text(-4,15+16*2,'f_{inter}=100','FontSize',14);
% t3 = text(-4,15+16*3,'f_{inter}=1','FontSize',14);
% t4 = text(-4,15+16*4,'f_{inter}=10','FontSize',14);
% t5 = text(-4,15+16*5,'f_{inter}=100','FontSize',14);
% t6 = text(-4,15+16*6,'f_{inter}=1','FontSize',14);
% t7 = text(-4,15+16*7,'f_{inter}=10','FontSize',14);
% t8 = text(-4,15+16*8,'f_{inter}=100','FontSize',14);
% 
% ts1 = text(-10,15+16*1,'{\sigma}_z=50','FontSize',14);
% ts4 = text(-10,15+16*4,'{\sigma}_z=100','FontSize',14);
% ts7 = text(-10,15+16*7,'{\sigma}_z=1000','FontSize',14);
% 
% set(t0, 'rotation', 90)
% set(t1, 'rotation', 90)
% set(t2, 'rotation', 90)
% set(t3, 'rotation', 90)
% set(t4, 'rotation', 90)
% set(t5, 'rotation', 90)
% set(t6, 'rotation', 90)
% set(t7, 'rotation', 90)
% set(t8, 'rotation', 90)
% set(ts1, 'rotation', 90)
% set(ts4, 'rotation', 90)
% set(ts7, 'rotation', 90)
% 
% 
% text(2+16*0,147,'f_{inter}=1','FontSize',14)
% text(2+16*1,147,'f_{inter}=10','FontSize',14)
% text(2+16*2,147,'f_{inter}=100','FontSize',14)
% text(2+16*3,147,'f_{inter}=1','FontSize',14)
% text(2+16*4,147,'f_{inter}=10','FontSize',14)
% text(2+16*5,147,'f_{inter}=100','FontSize',14)
% text(2+16*6,147,'f_{inter}=1','FontSize',14)
% text(2+16*7,147,'f_{inter}=10','FontSize',14)
% text(2+16*8,147,'f_{inter}=100','FontSize',14)
% 
% text(2+16*1,152,'{\sigma}_z=50','FontSize',14)
% text(2+16*4,152,'{\sigma}_z=100','FontSize',14)
% text(2+16*7,152,'{\sigma}_z=1000','FontSize',14)

%xlabel({'';'';'Simulation ID S.x'}, 'FontSize', FontSizeAll);
%ylabel({'Simulation ID S.y';'';'';''}, 'FontSize', FontSizeAll);
set(gca, 'CLim', [0, 1]);
colorbar;colormap hot;
set(gca,'visible','off');
set(gcf, 'Color', 'w');

title(['Convergence measured by the earliest timestep that the dice score remained >' num2str(Convergence_Threshold)],'FontSize',FontSizeAll)
if(savepdf)
	export_fig([Save_Directory 'ConvergenceMin' num2str(uint32(Convergence_Threshold*100))], '-pdf', '-png', '-painters', '-a1', '-q101')
end

dlmwrite([Save_Directory 'ConvergenceMin.dat'], ConvergenceMinMatrix, ' ');













MeansUnifs = [];
MeansFlows = [];
MeansGeodesics = [];
MeansSynaptics = [];
MeansFinished = [];

%% Plot Stuff
for plotby = 1:8
    
    if(plotby == 1)
        mylegend = {'Network connectivity 1', 'Network connectivity 2'};
    elseif(plotby == 2)
        mylegend = {'Clearable protein', 'Unclearable protein'};
    elseif(plotby == 3)
        mylegend = {'All','All 2', 'All 3', 'E2RS', 'E2IB', 'I2FS', 'I2LTS', 'E4RS', 'I4FS', 'I4LTS', 'E5IB', 'E5RS', 'I5FS', 'I5LTS', 'E6RS', 'I6FS', 'I6LTS'};
    elseif(plotby == 4)
        mylegend = {'Misfold Rate 0.08','Misfold Rate 0.09'};
    elseif(plotby == 5)
        mylegend = {'No Diffusion','Diffusion Speed 50', 'Diffusion Speed 500'};
    elseif(plotby == 6)
        mylegend = {'No Active Transport','Active Transport fraction 0.0001', 'Active Transport fraction 0.001'};
    elseif(plotby == 7)
        mylegend = {'No synaptic transfer','Synaptic transfer with loss of function', 'Synaptic transfer with toxic gain of funciton'};
    elseif(plotby == 8)
        mylegend = {'Intracolumnar preference','No preference', 'Intercolumnar preference'};
    end
    notplotby = setdiff(1:NumVariables, plotby);
    
    %Prepare non uniformity value data for plot
    clear plotterunifvar;
    clear plotterflowvar;
    clear plottergeodesicvar;
    clear plottersynapticvar;
    clear plotterfinishedvar;
    counters = zeros(VariablesSize(plotby),1);
    CurrentExperimentParameterSet = ones(1,NumVariables);
    for CurrentExperiment = 1:TotalExperiments
        z = CurrentExperimentParameterSet;
        parameter = z(plotby);
        counters(parameter) = counters(parameter) + 1;
        
        plotterunifvar(parameter,counters(parameter)) = AllUnifValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8));
        plotterflowvar(parameter,counters(parameter)) = AllFlowValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8));
        plottergeodesicvar(parameter,counters(parameter)) = AllGeodesicValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8));
        plottersynapticvar(parameter,counters(parameter)) = AllSynapticValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8));
        plotterfinishedvar(parameter,counters(parameter)) = TimeFinishedValues(z(1),z(2),z(3),z(4),z(5),z(6),z(7),z(8));
        
        if(CurrentExperiment < TotalExperiments)
            k = NumVariables;
            CurrentExperimentParameterSet(k) = CurrentExperimentParameterSet(k) + 1;
            while(1)
                if(CurrentExperimentParameterSet(k) > VariablesSize(k))
                    CurrentExperimentParameterSet(k) = 1;
                    k = k - 1;
                    CurrentExperimentParameterSet(k) = CurrentExperimentParameterSet(k) + 1;
                else
                    break;
                end
            end
        end
    end
    
    meanunif = mean(plotterunifvar,2);
    meanflow = mean(plotterflowvar,2);
    meangeodesic = mean(plottergeodesicvar,2);
    meansynaptic = mean(plottersynapticvar,2);
    meanfinished = mean(plotterfinishedvar,2);
    
    MeansUnifs(1:numel(meanunif),plotby) = meanunif;
    MeansFlows(1:numel(meanflow),plotby) = meanflow;
    MeansGeodesics(1:numel(meangeodesic),plotby) = meangeodesic;
    MeansSynaptics(1:numel(meansynaptic),plotby) = meansynaptic;
    MeansFinished(1:numel(meanfinished),plotby) = meanfinished;
end

figure;imagesc(MeansUnifs); MeansUnifs
figure;imagesc(MeansFlows); MeansFlows
figure;imagesc(MeansSynaptics); MeansSynaptics
figure;imagesc(MeansGeodesics); MeansGeodesics
figure;imagesc(MeansFinished); MeansFinished

for plotby = 1:8
    if(plotby == 1)
        mylegend = {'Network connectivity 1', 'Network connectivity 2'};
    elseif(plotby == 2)
        mylegend = {'Clearable protein', 'Unclearable protein'};
    elseif(plotby == 3)
        mylegend = {'All','All 2', 'All 3', 'E2RS', 'E2IB', 'I2FS', 'I2LTS', 'E4RS', 'I4FS', 'I4LTS', 'E5IB', 'E5RS', 'I5FS', 'I5LTS', 'E6RS', 'I6FS', 'I6LTS'};
    elseif(plotby == 4)
        mylegend = {'Misfold Rate 0.08','Misfold Rate 0.09'};
    elseif(plotby == 5)
        mylegend = {'No Diffusion','Diffusion Speed 50', 'Diffusion Speed 500'};
    elseif(plotby == 6)
        mylegend = {'No Active Transport','Active Transport fraction 0.0001', 'Active Transport fraction 0.001'};
    elseif(plotby == 7)
        mylegend = {'No synaptic transfer','Synaptic transfer with loss of function', 'Synaptic transfer with toxic gain of funciton'};
    elseif(plotby == 8)
        mylegend = {'Intracolumnar preference','No preference', 'Intercolumnar preference'};
    end
    notplotby = setdiff(1:NumVariables, plotby);
    
    %Prepare convergence value data for plot
    clear ConvergenceMinMatrixChosen;
    CurrentExperimentParameterSetOther = ones(1,NumVariables);
    counters = zeros(VariablesSize(plotby),1);
    for CurrentExperimentOther = 1:TotalExperiments
        parameterOther = CurrentExperimentParameterSetOther(plotby);
        notparameterOther = CurrentExperimentParameterSetOther(notplotby);
        CurrentExperimentParameterSet = ones(1,NumVariables);
        for CurrentExperiment = 1:TotalExperiments
            parameter = CurrentExperimentParameterSet(plotby);
            notparameter = CurrentExperimentParameterSet(notplotby);
            
            if(sum(notparameter ~= notparameterOther) == 0)
                counters(parameter) = counters(parameter) + 1;
                tempvalue = ConvergenceMinMatrix(CurrentExperimentOther, CurrentExperiment);
                ConvergenceMinMatrixChosen(parameter,CurrentExperimentOther) = tempvalue;
            end
            
            if(CurrentExperiment < TotalExperiments)
                k = NumVariables;
                CurrentExperimentParameterSet(k) = CurrentExperimentParameterSet(k) + 1;
                while(1)
                    if(CurrentExperimentParameterSet(k) > VariablesSize(k))
                        CurrentExperimentParameterSet(k) = 1;
                        k = k - 1;
                        CurrentExperimentParameterSet(k) = CurrentExperimentParameterSet(k) + 1;
                    else
                        break;
                    end
                end
            end
        end
        
        if(CurrentExperimentOther < TotalExperiments)
            k = NumVariables;
            CurrentExperimentParameterSetOther(k) = CurrentExperimentParameterSetOther(k) + 1;
            while(1)
                if(CurrentExperimentParameterSetOther(k) > VariablesSize(k))
                    CurrentExperimentParameterSetOther(k) = 1;
                    k = k - 1;
                    CurrentExperimentParameterSetOther(k) = CurrentExperimentParameterSetOther(k) + 1;
                else
                    break;
                end
            end
        end
    end 
end



AllVals = zeros(sum(VariablesSize));
AllNumVals = zeros(sum(VariablesSize));
CurrentExperimentParameterSetOther = ones(1,NumVariables);
counters = zeros(VariablesSize(plotby),1);
for CurrentExperimentOther = 1:TotalExperiments
    CurrentExperimentOther
    CurrentExperimentParameterSet = ones(1,NumVariables);
    for CurrentExperiment = 1:TotalExperiments
        tempvalue = ConvergenceMinMatrix(CurrentExperimentOther, CurrentExperiment);
        
        
        set1 = [CurrentExperimentParameterSet(1)];
        set2 = [CurrentExperimentParameterSetOther(1)];
        for parameter = 2:numel(VariablesSize)
            set1 = [set1 sum(VariablesSize(1:parameter-1))+CurrentExperimentParameterSet(parameter)];
            set2 = [set2 sum(VariablesSize(1:parameter-1))+CurrentExperimentParameterSetOther(parameter)];
        end
        AllVals(set1,set2) = AllVals(set1,set2) + tempvalue;
        AllNumVals(set1,set2) = AllNumVals(set1,set2) + 1;
        
        if(CurrentExperiment < TotalExperiments)
            k = NumVariables;
            CurrentExperimentParameterSet(k) = CurrentExperimentParameterSet(k) + 1;
            while(1)
                if(CurrentExperimentParameterSet(k) > VariablesSize(k))
                    CurrentExperimentParameterSet(k) = 1;
                    k = k - 1;
                    CurrentExperimentParameterSet(k) = CurrentExperimentParameterSet(k) + 1;
                else
                    break;
                end
            end
        end
    end
    
    if(CurrentExperimentOther < TotalExperiments)
        k = NumVariables;
        CurrentExperimentParameterSetOther(k) = CurrentExperimentParameterSetOther(k) + 1;
        while(1)
            if(CurrentExperimentParameterSetOther(k) > VariablesSize(k))
                CurrentExperimentParameterSetOther(k) = 1;
                k = k - 1;
                CurrentExperimentParameterSetOther(k) = CurrentExperimentParameterSetOther(k) + 1;
            else
                break;
            end
        end
    end
end
AllValsMeans = AllVals./AllNumVals;
save('AllValsMeans.mat', 'AllValsMeans');





FontSizeAll=18;savepdf=1;
load('AllValsMeans.mat');
close all;
width = 40;
height = 40;
h2 = figure('Units','centimeters',...
    'PaperUnits','centimeters', ...
	'PaperSize',[width height], ...
	'PaperPositionMode','manual', ...
	'InvertHardcopy', 'on', ...
    'Position',[0 0 width height],...
    'Renderer','painters');
axes('Position',[.35 .35 .6 .6]);
imagesc(AllValsMeans);
for i = [0 2 4 21 23 26 29 32 35]; line(xlim+[-1 0],[1,1]*i + 0.5,'color','k','LineWidth',2,'Clipping','off');  end
for i = [0 2 4 21 23 26 29 32 35]; line([1,1]*i + 0.5,ylim+[0 +0],'color','k','LineWidth',2,'Clipping','off');  end
set(gca,'FontSize',FontSizeAll)
%title([''],'FontSize',FontSizeAll)
%set(gca, 'CLim', [0, 1]);
colorbar;
set(gca,'visible','off');
set(gcf, 'Color', 'w');
FontSizeText = 14;
t2 = text(-8.5,1,'Network connectivity 1','FontSize',FontSizeText);
t2 = text(-8.5,2,'Network connectivity 2','FontSize',FontSizeText);
t2 = text(-5.8,3,'Soluble protein','FontSize',FontSizeText);
t2 = text(-6.3,4,'Insoluble protein','FontSize',FontSizeText);
t2 = text(-4.0,5,'Seed All 1','FontSize',FontSizeText);
t2 = text(-4.0,6,'Seed All 2','FontSize',FontSizeText);
t2 = text(-4.0,7,'Seed All 3','FontSize',FontSizeText);
t2 = text(-4.4,8,'Seed L2RS','FontSize',FontSizeText);
t2 = text(-4.1,9,'Seed L2IB','FontSize',FontSizeText);
t2 = text(-4.4,10,'Seed L2FS','FontSize',FontSizeText);
t2 = text(-4.8,11,'Seed L2LTS','FontSize',FontSizeText);
t2 = text(-4.4,12,'Seed L4RS','FontSize',FontSizeText);
t2 = text(-4.4,13,'Seed L4FS','FontSize',FontSizeText);
t2 = text(-4.8,14,'Seed L4LTS','FontSize',FontSizeText);
t2 = text(-4.4,15,'Seed L5RS','FontSize',FontSizeText);
t2 = text(-4.1,16,'Seed L5IB','FontSize',FontSizeText);
t2 = text(-4.4,17,'Seed L5FS','FontSize',FontSizeText);
t2 = text(-4.8,18,'Seed L5LTS','FontSize',FontSizeText);
t2 = text(-4.4,19,'Seed L6RS','FontSize',FontSizeText);
t2 = text(-4.4,20,'Seed L6FS','FontSize',FontSizeText);
t2 = text(-4.8,21,'Seed L6LTS','FontSize',FontSizeText);
t2 = text(-7.4,22,'Low misfolding rate','FontSize',FontSizeText);
t2 = text(-7.5,23,'High misfolding rate','FontSize',FontSizeText);
t2 = text(-4.7,24,'No diffusion','FontSize',FontSizeText);
t2 = text(-7.55,25,'Low diffusion speed','FontSize',FontSizeText);
t2 = text(-7.7,26,'High diffusion speed','FontSize',FontSizeText);
t2 = text(-7.2,27,'No active transport','FontSize',FontSizeText);
t2 = text(-8.1,28,'Weak active transport','FontSize',FontSizeText);
t2 = text(-8.5,29,'Strong active transport','FontSize',FontSizeText);
t2 = text(-7.6,30,'No synaptic transfer','FontSize',FontSizeText);
t2 = text(-8.1,31,'Low synaptic transfer','FontSize',FontSizeText);
t2 = text(-8.2,32,'High synaptic transfer','FontSize',FontSizeText);
t2 = text(-9.1,33,'Intercolumnar avoidance','FontSize',FontSizeText);
t2 = text(-7.8,34,'No spread selectivity','FontSize',FontSizeText);
t2 = text(-9.0,35,'Intercolumnar selectivity','FontSize',FontSizeText);
colormap jet;
t2 = text(-10.5,1,'1.','FontSize',FontSizeText);
t2 = text(-10.5,2,'2.','FontSize',FontSizeText);
t2 = text(-10.5,3,'3.','FontSize',FontSizeText);
t2 = text(-10.5,4,'4.','FontSize',FontSizeText);
t2 = text(-10.5,5,'5.','FontSize',FontSizeText);
t2 = text(-10.5,6,'6.','FontSize',FontSizeText);
t2 = text(-10.5,7,'7.','FontSize',FontSizeText);
t2 = text(-10.5,8,'8.','FontSize',FontSizeText);
t2 = text(-10.5,9,'9.','FontSize',FontSizeText);
t2 = text(-10.5,10,'10.','FontSize',FontSizeText);
t2 = text(-10.5,11,'11.','FontSize',FontSizeText);
t2 = text(-10.5,12,'12.','FontSize',FontSizeText);
t2 = text(-10.5,13,'13.','FontSize',FontSizeText);
t2 = text(-10.5,14,'14.','FontSize',FontSizeText);
t2 = text(-10.5,15,'15.','FontSize',FontSizeText);
t2 = text(-10.5,16,'16.','FontSize',FontSizeText);
t2 = text(-10.5,17,'17.','FontSize',FontSizeText);
t2 = text(-10.5,18,'18.','FontSize',FontSizeText);
t2 = text(-10.5,19,'19.','FontSize',FontSizeText);
t2 = text(-10.5,20,'20.','FontSize',FontSizeText);
t2 = text(-10.5,21,'21.','FontSize',FontSizeText);
t2 = text(-10.5,22,'22.','FontSize',FontSizeText);
t2 = text(-10.5,23,'23.','FontSize',FontSizeText);
t2 = text(-10.5,24,'24.','FontSize',FontSizeText);
t2 = text(-10.5,25,'25.','FontSize',FontSizeText);
t2 = text(-10.5,26,'26.','FontSize',FontSizeText);
t2 = text(-10.5,27,'27.','FontSize',FontSizeText);
t2 = text(-10.5,28,'28.','FontSize',FontSizeText);
t2 = text(-10.5,29,'29.','FontSize',FontSizeText);
t2 = text(-10.5,30,'30.','FontSize',FontSizeText);
t2 = text(-10.5,31,'31.','FontSize',FontSizeText);
t2 = text(-10.5,32,'32.','FontSize',FontSizeText);
t2 = text(-10.5,33,'33.','FontSize',FontSizeText);
t2 = text(-10.5,34,'34.','FontSize',FontSizeText);
t2 = text(-10.5,35,'35.','FontSize',FontSizeText);

% set(t0, 'rotation', 90)
% text(2+16*0,147,'f_{inter}=1','FontSize',14)
if(savepdf)
	export_fig([Save_Directory 'Convergence35x35'], '-pdf', '-png', '-painters', '-a1', '-q101')
end









for i = 1

close all;
    width = 30;    height = 5;
    h2 = figure('visible','on','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
    imagesc(ConvergenceMinMatrixChosen);
    title(['Convergence for ' VariablesNames{plotby} ': the earliest timestep that dice score remained >' num2str(Convergence_Threshold)],'FontSize',FontSizeAll)
    %ylabel('Time to full network breakdown', 'FontSize', FontSizeAll);
    %xlabel('', 'FontSize', FontSizeAll);
    %legend();
    set(gca,'FontSize',FontSizeAll);
    set(gcf, 'Color', 'w');
    set(gca, 'CLim', [0, 1]);
    colorbar;colormap hot;
    set(gca,'visible','off');
    if(savepdf) export_fig([Save_Directory 'ConvergenceMin' VariablesNames{plotby} num2str(uint32(Convergence_Threshold*100))], '-pdf', '-png', '-painters', '-a1', '-q101'); end
















    
    %Plot non uniformity values
%     close all;
%     width = 30;    height = 30;
%     h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
%     plot(plotterunifvar');
%     title(['Non uniformity mean values separated by ' VariablesNames{plotby}] ,'FontSize',FontSizeAll)
%     ylabel('Non uniformity value', 'FontSize', FontSizeAll);
%     %xlabel('', 'FontSize', FontSizeAll);
%     legend(mylegend);
%     set(gca,'FontSize',FontSizeAll);
%     set(gcf, 'Color', 'w');
%     %set(gca, 'CLim', [0, 1]);
%     %colorbar;colormap hot;
%     %set(gca,'visible','off'); 
%     if(savepdf) export_fig([Save_Directory 'NonUniformity' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end
    
    close all;
    width = 30;    height = 5;
    h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
    imagesc(plotterunifvar);
    title(['Non uniformity mean values separated by ' VariablesNames{plotby}],'FontSize',FontSizeAll)
    %ylabel('Time to full network breakdown', 'FontSize', FontSizeAll);
    %xlabel('', 'FontSize', FontSizeAll);
    %legend();
    set(gca,'FontSize',FontSizeAll);
    set(gcf, 'Color', 'w');
    %set(gca, 'CLim', [0, 1]);
    colorbar;colormap hot;
    %set(gca,'visible','off');
    if(savepdf) export_fig([Save_Directory 'NonUniformity' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end

    
    
    
    
    
    
    
    
    
%     close all;
%     width = 30;    height = 30;
%     h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
%     plot(plotterflowvar');
%     title(['Flow Difference R^2 values separated by ' VariablesNames{plotby}] ,'FontSize',FontSizeAll)
%     ylabel('Flow Difference R^2', 'FontSize', FontSizeAll);
%     %xlabel('', 'FontSize', FontSizeAll);
%     legend(mylegend);
%     set(gca,'FontSize',FontSizeAll);
%     set(gcf, 'Color', 'w');
%     %set(gca, 'CLim', [0, 1]);
%     %colorbar;colormap hot;
%     %set(gca,'visible','off');    
%     if(savepdf) export_fig([Save_Directory 'FlowDifference' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end

    close all;
    width = 30;    height = 5;
    h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
    imagesc(plotterflowvar);
    title(['Flow Difference R^2 values separated by ' VariablesNames{plotby}],'FontSize',FontSizeAll)
    %ylabel('Time to full network breakdown', 'FontSize', FontSizeAll);
    %xlabel('', 'FontSize', FontSizeAll);
    %legend();
    set(gca,'FontSize',FontSizeAll);
    set(gcf, 'Color', 'w');
    %set(gca, 'CLim', [0, 1]);
    colorbar;colormap hot;
    %set(gca,'visible','off');
    if(savepdf) export_fig([Save_Directory 'FlowDifference' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end


    
    
    
    
    
    
    
    
%     close all;
%     width = 30;    height = 30;
%     h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
%     plot(plottergeodesicvar');
%     title(['Geodesic distance to seeds R^2 values separated by ' VariablesNames{plotby}] ,'FontSize',FontSizeAll)
%     ylabel('Geodesic distance to seeds R^2', 'FontSize', FontSizeAll);
%     %xlabel('', 'FontSize', FontSizeAll);
%     legend(mylegend);
%     set(gca,'FontSize',FontSizeAll);
%     set(gcf, 'Color', 'w');
%     %set(gca, 'CLim', [0, 1]);
%     %colorbar;colormap hot;
%     %set(gca,'visible','off');
%     if(savepdf) export_fig([Save_Directory 'Geodesics' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end
    
    close all;
    width = 30;    height = 5;
    h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
    imagesc(plottergeodesicvar);
    title(['Geodesic distance to seeds R^2 values separated by ' VariablesNames{plotby}],'FontSize',FontSizeAll)
    %ylabel('Time to full network breakdown', 'FontSize', FontSizeAll);
    %xlabel('', 'FontSize', FontSizeAll);
    %legend();
    set(gca,'FontSize',FontSizeAll);
    set(gcf, 'Color', 'w');
    %set(gca, 'CLim', [0, 1]);
    colorbar;colormap hot;
    %set(gca,'visible','off');
    if(savepdf) export_fig([Save_Directory 'Geodesics' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end

    
    
    
    
%     close all;
%     width = 30;    height = 30;
%     h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
%     plot(plottersynapticvar');
%     title(['Synaptic strength difference R^2 values separated by ' VariablesNames{plotby}] ,'FontSize',FontSizeAll)
%     ylabel('Synaptic strength difference R^2', 'FontSize', FontSizeAll);
%     %xlabel('', 'FontSize', FontSizeAll);
%     legend(mylegend);
%     set(gca,'FontSize',FontSizeAll);
%     set(gcf, 'Color', 'w');
%     %set(gca, 'CLim', [0, 1]);
%     %colorbar;colormap hot;
%     %set(gca,'visible','off');
%     if(savepdf) export_fig([Save_Directory 'Synaptic' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end
    
    close all;
    width = 30;    height = 5;
    h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
    imagesc(plottersynapticvar);
    title(['Synaptic strength difference R^2 values separated by ' VariablesNames{plotby}],'FontSize',FontSizeAll)
    %ylabel('Time to full network breakdown', 'FontSize', FontSizeAll);
    %xlabel('', 'FontSize', FontSizeAll);
    %legend();
    set(gca,'FontSize',FontSizeAll);
    set(gcf, 'Color', 'w');
    %set(gca, 'CLim', [0, 1]);
    colorbar;colormap hot;
    %set(gca,'visible','off');
    if(savepdf) export_fig([Save_Directory 'Synaptic' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end

    
    
    
    
    
    
%     close all;
%     width = 30;    height = 30;
%     h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
%     plot(plotterfinishedvar');
%     title(['Time to full network breakdown values separated by ' VariablesNames{plotby}] ,'FontSize',FontSizeAll)
%     ylabel('Time to full network breakdown', 'FontSize', FontSizeAll);
%     %xlabel('', 'FontSize', FontSizeAll);
%     legend(mylegend);
%     set(gca,'FontSize',FontSizeAll);
%     set(gcf, 'Color', 'w');
%     %set(gca, 'CLim', [0, 1]);
%     %colorbar;colormap hot;
%     %set(gca,'visible','off');
%     if(savepdf) export_fig([Save_Directory 'Finished' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end
    
    close all;
    width = 30;    height = 5;
    h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
    imagesc(plotterfinishedvar);
    title(['Time to full network breakdown values separated by ' VariablesNames{plotby}],'FontSize',FontSizeAll)
    %ylabel('Time to full network breakdown', 'FontSize', FontSizeAll);
    %xlabel('', 'FontSize', FontSizeAll);
    %legend();
    set(gca,'FontSize',FontSizeAll);
    set(gcf, 'Color', 'w');
    %set(gca, 'CLim', [0, 1]);
    colorbar;colormap hot;
    %set(gca,'visible','off');
    if(savepdf) export_fig([Save_Directory 'Finished' VariablesNames{plotby}], '-pdf', '-png', '-painters', '-a1', '-q101'); end



    
    
    
    
    close all;
    width = 30;    height = 5;
    h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],'PaperUnits','centimeters','PaperSize',[width height],'PaperPositionMode','auto', 'InvertHardcopy', 'on', 'Renderer','painters');
    imagesc(ConvergenceMinMatrixChosen);
    title(['Convergence for ' VariablesNames{plotby} ': the earliest timestep that dice score remained >' num2str(Convergence_Threshold)],'FontSize',FontSizeAll)
    %ylabel('Time to full network breakdown', 'FontSize', FontSizeAll);
    %xlabel('', 'FontSize', FontSizeAll);
    %legend();
    set(gca,'FontSize',FontSizeAll);
    set(gcf, 'Color', 'w');
    set(gca, 'CLim', [0, 1]);
    colorbar;colormap hot;
    set(gca,'visible','off');
    if(savepdf) export_fig([Save_Directory 'ConvergenceMin' VariablesNames{plotby} num2str(uint32(Convergence_Threshold*100))], '-pdf', '-png', '-painters', '-a1', '-q101'); end


end



