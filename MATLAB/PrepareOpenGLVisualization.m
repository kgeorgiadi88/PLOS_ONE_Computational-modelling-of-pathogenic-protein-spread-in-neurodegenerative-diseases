function PrepareOpenGLVisualization( CurrentDirectory, VideoSpikes, VideoConcentrations, VideoDamage, NumColumns, t, CellTypes, CellColumns, NumTypePerColumn, Adjacency )
%Get Fourier Transform of VideoSpikes
FourierTransformWindow = 200;
VideoFrequencies = zeros(size(VideoSpikes));
for frame = 1:size(VideoSpikes,2)
    StartWindow = max([1 frame-floor(FourierTransformWindow/2)]);
    EndWindow = min([size(VideoSpikes,2) frame+ceil(FourierTransformWindow/2)]);
    VideoFrequencies(:,frame) = mean(VideoSpikes(:,StartWindow:EndWindow),2);
end
VideoMinFrequencies = min(VideoFrequencies, [], 2);
VideoMaxFrequencies = max(VideoFrequencies, [], 2);

%Get 3D points for visualization
Points3D = GraphTo3D(t, CellTypes, CellColumns, NumTypePerColumn);

%Get Summary for visualization
[SummaryPoints, SummaryColumns, TotalPoints] = Summarize3Dpoints(Points3D, CellTypes, CellColumns);
SummaryAdjacency = SummarizeAdjacency(Adjacency, CellTypes, CellColumns, TotalPoints);
SummaryConcentrations = zeros(NumColumns*40, size(VideoConcentrations,2));
SummaryDamage = zeros(NumColumns*40, size(VideoDamage,2));
SummarySpikes = zeros(NumColumns*40, size(VideoSpikes,2));
SummaryFrequencies = zeros(NumColumns*40, size(VideoSpikes,2));
for neuron = 1:size(VideoConcentrations,1)
    SummaryConcentrations(CellTypes(neuron)+40*CellColumns(neuron),:) = SummaryConcentrations(CellTypes(neuron)+40*CellColumns(neuron),:) + VideoConcentrations(neuron,:);
    SummaryDamage(CellTypes(neuron)+40*CellColumns(neuron),:) = SummaryDamage(CellTypes(neuron)+40*CellColumns(neuron),:) + VideoDamage(neuron,:);
    SummarySpikes(CellTypes(neuron)+40*CellColumns(neuron),:) = SummarySpikes(CellTypes(neuron)+40*CellColumns(neuron),:) + VideoSpikes(neuron,:);
    SummaryFrequencies(CellTypes(neuron)+40*CellColumns(neuron),:) = SummaryFrequencies(CellTypes(neuron)+40*CellColumns(neuron),:) + VideoFrequencies(neuron,:);
end
for column = 0:NumColumns-1
    for type = 1:40
        if(NumTypePerColumn(type)>0)
            SummaryConcentrations(type+column*40,:) = SummaryConcentrations(type+column*40,:)/NumTypePerColumn(type);
            SummaryDamage(type+column*40,:) = SummaryDamage(type+column*40,:)/NumTypePerColumn(type);
            SummaryFrequencies(type+column*40,:) = SummaryFrequencies(type+column*40,:)/NumTypePerColumn(type);
        end
    end
end
SummaryMinFrequencies = min(SummaryFrequencies, [], 2);
SummaryMaxFrequencies = max(SummaryFrequencies, [], 2);

dlmwrite([CurrentDirectory 'VideoPoints.dat'], Points3D, ' ');
dlmwrite([CurrentDirectory 'VideoAdjacency.dat'], Adjacency, ' ');
dlmwrite([CurrentDirectory 'VideoFrequencies.dat'], VideoFrequencies, ' ');
dlmwrite([CurrentDirectory 'VideoMinFrequencies.dat'], VideoMinFrequencies, ' ');
dlmwrite([CurrentDirectory 'VideoMaxFrequencies.dat'], VideoMaxFrequencies, ' ');
dlmwrite([CurrentDirectory 'SummaryPoints.dat'], SummaryPoints, ' ');
dlmwrite([CurrentDirectory 'SummaryColumns.dat'], SummaryColumns, ' ');
dlmwrite([CurrentDirectory 'SummaryAdjacency.dat'], SummaryAdjacency, ' ');
dlmwrite([CurrentDirectory 'SummaryConcentrations.dat'], SummaryConcentrations, ' ');
dlmwrite([CurrentDirectory 'SummaryDamage.dat'], SummaryDamage, ' ');
dlmwrite([CurrentDirectory 'SummarySpikes.dat'], SummarySpikes, ' ');
dlmwrite([CurrentDirectory 'SummaryFrequencies.dat'], SummaryFrequencies, ' ');
dlmwrite([CurrentDirectory 'SummaryMinFrequencies.dat'], SummaryMinFrequencies, ' ');
dlmwrite([CurrentDirectory 'SummaryMaxFrequencies.dat'], SummaryMaxFrequencies, ' ');

end