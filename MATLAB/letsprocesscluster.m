close all; clear variables; clc;
%Check if simulation finished all the way.
SimulationFinished = dlmread('Finished.dat');
if(SimulationFinished ~= 1)
    fprintf('\n\n!!!!!\nREAD ERROR. Simulation never finished!!!!!!!\n!!!!!\n\n');
    exit;
end

%Load Data
MetaData = dlmread('SaveMetaData.dat');
Adjacency = dlmread('Adjacency.dat');
CellColumns = dlmread('SaveCellColumns.dat');
CellTypes = dlmread('SaveCellTypes.dat');

VideoConcentrations = dlmread('VideoConcentrations.dat');
VideoDamage = dlmread('VideoDamage.dat');
VideoSpikes = dlmread('VideoSpikes.dat');
VideoTimesteps = dlmread('VideoTimesteps.dat');
TotalQuantity = dlmread('SaveTotalQuantity.dat');

OrderIndices = dlmread('AtrophyOrderIndices.dat');
OrderTimesteps = dlmread('AtrophyOrderTimesteps.dat');
OrderTypes = dlmread('AtrophyOrderTypes.dat');
OrderColumns = dlmread('AtrophyOrderColumns.dat');

OrderIncomingWeights = dlmread('AtrophyOrderIncomingWeights.dat');
OrderOutcomingWeights = dlmread('AtrophyOrderOutcomingWeights.dat');
OrderIncomingWeightsOtherTypes = dlmread('AtrophyOrderIncomingWeightsOtherTypes.dat');
OrderOutcomingWeightsOtherTypes = dlmread('AtrophyOrderOutcomingWeightsOtherTypes.dat');

OrderInflow = dlmread('AtrophyOrderInflow.dat');
OrderOutflow = dlmread('AtrophyOrderOutflow.dat');
OrderInflowOtherTypes = dlmread('AtrophyOrderInflowOtherTypes.dat');
OrderOutflowOtherTypes = dlmread('AtrophyOrderOutflowOtherTypes.dat');

VideoColors = dlmread('VideoColors.dat');

%Create MetaData
NumNeurons = MetaData(1);
NumColumns = MetaData(2);
NumSectionsPerNeuron = MetaData(3);
TotalTimesteps = MetaData(4);
%Because the saved file doesn't have perfect accuracy..............
TotalTimesteps = TotalTimesteps + 1;
dt = MetaData(5);
TimestepsPerFrame = MetaData(6);
NumNeuronsPerColumn = NumNeurons/NumColumns;
tstop = dt*(TotalTimesteps-1);
timesteps = 0:dt:tstop;

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


CurrentDirectory = pwd;
CurrentDirectory = [CurrentDirectory '/'];
PrepareOpenGLVisualization( CurrentDirectory, VideoSpikes, VideoConcentrations, VideoDamage, NumColumns, t, CellTypes, CellColumns, NumTypePerColumn, Adjacency);

%Calculating Dijkstra for all sources and sinks/destinations
DijkstraAll = zeros(NumNeurons);
AdjacencyDistances = 1./Adjacency;
AdjacencyDistances(Adjacency == 0) = 0;
GraphCell = AdjacencyToCell(AdjacencyDistances);
if(nnz(Adjacency) ~= nnz(AdjacencyDistances))
    nnz(Adjacency)
    exit;
end
for neuron = 1:NumNeurons
    DistanceVector = DijkstraCell(GraphCell, neuron);
    DijkstraAll(neuron,:) = DistanceVector';
end


%Finding distances from nexopathy source
RowsToCheck = OrderIndices(1)+1;
OrderDistanceFromSource = zeros(1,NumNeurons);
for i = 1:NumNeurons
    To = OrderIndices(i)+1;
    OrderDistanceFromSource(i) = min(DijkstraAll(RowsToCheck,To));
end

%Preparing data for plots/scatters
OrderTime = OrderTimesteps*dt;

OrderWeightsDifference = OrderIncomingWeights - OrderOutcomingWeights;
OrderFlowDifference = OrderInflow-OrderOutflow;
OrderWeightsDifferenceOtherTypes = OrderIncomingWeightsOtherTypes - OrderOutcomingWeightsOtherTypes;
OrderFlowDifferenceOtherTypes = OrderInflowOtherTypes - OrderOutflowOtherTypes;

OrderDistanceFromSourceNormalized = (OrderDistanceFromSource-min(OrderDistanceFromSource))/(max(OrderDistanceFromSource)-min(OrderDistanceFromSource));
OrderWeightsDifferenceNormalized = (OrderWeightsDifference-min(OrderWeightsDifference))/(max(OrderWeightsDifference)-min(OrderWeightsDifference));
OrderFlowDifferenceNormalized =  (OrderFlowDifference-min(OrderFlowDifference))/(max(OrderFlowDifference)-min(OrderFlowDifference));
OrderWeightsDifferenceOtherTypesNormalized =  (OrderWeightsDifferenceOtherTypes-min(OrderWeightsDifferenceOtherTypes))/(max(OrderWeightsDifferenceOtherTypes)-min(OrderWeightsDifferenceOtherTypes));
OrderFlowDifferenceOtherTypesNormalized =  (OrderFlowDifferenceOtherTypes-min(OrderFlowDifferenceOtherTypes))/(max(OrderFlowDifferenceOtherTypes)-min(OrderFlowDifferenceOtherTypes));

ScatterY = zeros(1,NumNeurons);
ScatterColors = zeros(NumNeurons,3);
for neuron = 1:NumNeurons
    type = OrderTypes(neuron);
    if(type == t.E2)
        ScatterY(neuron) = 20 + OrderColumns(neuron)*25;
    elseif(type == t.E2B)
        ScatterY(neuron) = 19 + OrderColumns(neuron)*25;
    elseif(type == t.I2)
        ScatterY(neuron) = 18 + OrderColumns(neuron)*25;
    elseif(type == t.I2L)
        ScatterY(neuron) = 17 + OrderColumns(neuron)*25;
    elseif(type == t.E4)
        ScatterY(neuron) = 15 + OrderColumns(neuron)*25;
    elseif(type == t.I4)
        ScatterY(neuron) = 14 + OrderColumns(neuron)*25;
    elseif(type == t.I4L)
        ScatterY(neuron) = 13 + OrderColumns(neuron)*25;
    elseif(type == t.E5B)
        ScatterY(neuron) = 10 + OrderColumns(neuron)*25;
    elseif(type == t.E5R)
        ScatterY(neuron) = 9 + OrderColumns(neuron)*25;
    elseif(type == t.I5)
        ScatterY(neuron) = 8 + OrderColumns(neuron)*25;
    elseif(type == t.I5L)
        ScatterY(neuron) = 7 + OrderColumns(neuron)*25;
    elseif(type == t.E6)
        ScatterY(neuron) = 5 + OrderColumns(neuron)*25;
    elseif(type == t.I6)
        ScatterY(neuron) = 4 + OrderColumns(neuron)*25;
    elseif(type == t.I6L)
        ScatterY(neuron) = 3 + OrderColumns(neuron)*25;
    end
    
    if(type == t.E2)
        ScatterColors(neuron,:) = VideoColors(1,:);
    elseif(type == t.E2B)
        ScatterColors(neuron,:) = VideoColors(2,:);
    elseif(type == t.I2)
        ScatterColors(neuron,:) = VideoColors(3,:);
    elseif(type == t.I2L)
        ScatterColors(neuron,:) = VideoColors(4,:);
    elseif(type == t.E4)
        ScatterColors(neuron,:) = VideoColors(5,:);
    elseif(type == t.I4)
        ScatterColors(neuron,:) = VideoColors(6,:);
    elseif(type == t.I4L)
        ScatterColors(neuron,:) = VideoColors(7,:);
    elseif(type == t.E5B)
        ScatterColors(neuron,:) = VideoColors(8,:);
    elseif(type == t.E5R)
        ScatterColors(neuron,:) = VideoColors(9,:);
    elseif(type == t.I5)
        ScatterColors(neuron,:) = VideoColors(10,:);
    elseif(type == t.I5L)
        ScatterColors(neuron,:) = VideoColors(11,:);
    elseif(type == t.E6)
        ScatterColors(neuron,:) = VideoColors(12,:);
    elseif(type == t.I6)
        ScatterColors(neuron,:) = VideoColors(13,:);
    elseif(type == t.I6L)
        ScatterColors(neuron,:) = VideoColors(14,:);
    end
end
ScatterColors = double(uint8(2*ScatterColors))/256;

%plotting total quantity over time
stopat = numel(TotalQuantity);
for i = numel(TotalQuantity):-1:1
    if(TotalQuantity(i) > 0)
        stopat = i;
        break;
    end
end
TotalQuantity = TotalQuantity(1:stopat);
startat = 1;
for i = 1:numel(TotalQuantity)
    if(TotalQuantity(i) > 0)
        startat = max(1,i-1);
        break;
    end
end
TotalQuantity = TotalQuantity(startat:end);
ding = 0;
dingcounter = 0;
while(1)
    dingcounter = dingcounter + 1;
    ding = TimestepsPerFrame*dingcounter+2;
    if(ding > numel(TotalQuantity))
        break;
    end
    TotalQuantitySmall(1,dingcounter) = TotalQuantity(ding);
end

save([CurrentDirectory 'Everything.mat']);
exit;
