function PlotDeathTimes( CurrentLoadDirectory, CurrentSaveDirectory, savepdf)
load([CurrentLoadDirectory 'Everything.mat'], 'OrderTime', 'ScatterY', 'ScatterColors', 'NumColumns', 'tstop');
%fig 4
FontSizeAll = 18;
width = 30;
height = 15;
h4 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
    'PaperUnits','centimeters',...
    'PaperSize',[width height],...
    'PaperPositionMode','auto',...
    'InvertHardcopy', 'on',...
    'Renderer','opengl'...
    );

hold on;
for i = [3 4 5 7 8 9 10 13 14 15 17 18 19 20]
    col1 = ScatterY == i;
    col2 = ScatterY == i+25;
    col3 = ScatterY == i+50;
    colall = col1 | col2 | col3;
    scatter(OrderTime(colall), ScatterY(colall), 600, ScatterColors(colall,:) ,'.');
end
plot([0 tstop], [25 25],'k')
plot([0 tstop], [50 50],'k')
hold off;
tcol1 = text(-15000,12,'Column 1','FontSize',FontSizeAll);
tcol2 = text(-15000,12+25,'Column 2','FontSize',FontSizeAll);
tcol3 = text(-15000,12+50,'Column 3','FontSize',FontSizeAll);
set(gca,'FontSize',FontSizeAll)
title('Time each neuron reached cellular death','FontSize',FontSizeAll)
xlabel('time','FontSize',FontSizeAll)
ylim([0 25*NumColumns])
xlim([0 tstop]);
set(gcf, 'Color', 'w');
set(gca,'ycolor',[1 1 1 ]); set(gca,'ytick',[]);
[~, hobj, ~, ~] = legend('L6LTS','L6FS','L6RS','L5LTS','L5FS','L5IB','L5RS','L4LTS','L4FS','L4RS','L2LTS','L2FS','L2IB', 'L2RS','Location','EastOutside');
M = findobj(hobj,'type','patch');
set(M,'MarkerSize',50);

if(savepdf)
    set(h4, 'Color', 'w');
    export_fig([CurrentSaveDirectory 'CellDeath.pdf'], '-pdf', '-opengl', '-a1', '-q101')
end

%fig 4 without limits
width = 30;
height = 15;
h4b = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
    'PaperUnits','centimeters',...
    'PaperSize',[width height],...
    'PaperPositionMode','auto',...
    'InvertHardcopy', 'on',...
    'Renderer','opengl'...
    );
hold on;
for i = [3 4 5 7 8 9 10 13 14 15 17 18 19 20]
    col1 = ScatterY == i;
    col2 = ScatterY == i+25;
    col3 = ScatterY == i+50;
    colall = col1 | col2 | col3;
    scatter(OrderTime(colall), ScatterY(colall), 600, ScatterColors(colall,:) ,'.');
end
MinTime = min(OrderTime);
MaxTime = max(OrderTime);
MeanTime = mean([MinTime MaxTime]);
TimeTotal = 1.1*(max(OrderTime) - min(OrderTime))+50;
Minxlim = MeanTime-TimeTotal/2;
Maxxlim = MeanTime+TimeTotal/2;
plot([0 tstop], [25 25],'k')
plot([0 tstop], [50 50],'k')
hold off;
tcola1 = text(Minxlim - 0.15*TimeTotal,12,'Column 1','FontSize',FontSizeAll);
tcola2 = text(Minxlim - 0.15*TimeTotal,12+25,'Column 2','FontSize',FontSizeAll);
tcola3 = text(Minxlim - 0.15*TimeTotal,12+50,'Column 3','FontSize',FontSizeAll);
set(gca,'FontSize',FontSizeAll)
title('Time each neuron reached cellular death','FontSize',FontSizeAll)
xlabel('time','FontSize',FontSizeAll)
ylim([0 25*NumColumns])
xlim([Minxlim Maxxlim]);
set(gcf, 'Color', 'w');
set(gca,'ycolor',[1 1 1 ]); set(gca,'ytick',[]);
[~, hobj, ~, ~] = legend('L6LTS','L6FS','L6RS','L5LTS','L5FS','L5IB','L5RS','L4LTS','L4FS','L4RS','L2LTS','L2FS','L2IB', 'L2RS','Location','EastOutside');
M = findobj(hobj,'type','patch');
set(M,'MarkerSize',50);

if(savepdf)
    set(h4b, 'Color', 'w');
    export_fig([CurrentSaveDirectory 'CellDeathNoLimits.pdf'], '-pdf', '-opengl', '-a1', '-q101')
end


end