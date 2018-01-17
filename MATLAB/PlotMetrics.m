function PlotMetrics(CurrentLoadDirectory, CurrentSaveDirectory, savepdf)
FontSizeAll = 16;
load([CurrentLoadDirectory 'Everything.mat'], 'OrderTime', 'OrderWeightsDifferenceNormalized', 'OrderFlowDifferenceNormalized', 'OrderDistanceFromSourceNormalized' );
%fig 2
TimeFinished = OrderTime(numel(OrderTime));
dlmwrite([CurrentSaveDirectory 'TimeFinished.dat'], TimeFinished);

width = 10;
height = 30;
h2 = figure('visible','off','Units','centimeters', 'Position',[0 0 width height],...
    'PaperUnits','centimeters',...
    'PaperSize',[width height],...
    'PaperPositionMode','auto',...
    'InvertHardcopy', 'on',...
    'Renderer','painters'...
    );




x = OrderTime;
y = OrderWeightsDifferenceNormalized;
p = polyfit(x,y,1);
yfit = polyval(p,x);
yresid = y - yfit;
SSresid = sum(yresid.^2);
SStotal = (length(y)-1) * var(y);
rsq = 1 - SSresid/SStotal;
subplot(3,1,1);scatter(OrderTime, OrderWeightsDifferenceNormalized, 100, '.');
set(gca,'FontSize',FontSizeAll)
hold on;
plot(OrderTime, yfit, 'r');
hold off;
title(['R^2=' num2str(rsq)],'FontSize',FontSizeAll)
xlabel('Time (msec)','FontSize',FontSizeAll)
ylabel('Synaptic Strength Difference','FontSize',FontSizeAll)
ylim([0 1])
dlmwrite([CurrentSaveDirectory 'SynDiffValue.dat'], rsq);



x = OrderTime;
y = OrderFlowDifferenceNormalized;
p = polyfit(x,y,1);
yfit = polyval(p,x);
% 	yfit = zeros(1,numel(y));
% 	maxt = max(OrderTime);
% 	mint = min(OrderTime);
% 	for myiter = 1:numel(y)
% 		t = OrderTime(myiter);
% 		yfit(myiter) = 1 - ((t - mint) / (maxt - mint));
% 	end
yresid = y - yfit;
SSresid = sum(yresid.^2);
SStotal = (length(y)-1) * var(y);
rsq = 1 - SSresid/SStotal;
subplot(3,1,2);
scatter(OrderTime, OrderFlowDifferenceNormalized, 100, '.');
set(gca,'FontSize',FontSizeAll)
hold on;
plot(OrderTime, yfit, 'r')
hold off;
title(['R^2=' num2str(rsq)],'FontSize',FontSizeAll)
xlabel('Time (msec)','FontSize',FontSizeAll)
ylabel('Flow Difference','FontSize',FontSizeAll)
ylim([0 1])
dlmwrite([CurrentSaveDirectory 'FlowDiffValue.dat'], rsq);


x = OrderTime;
y = OrderDistanceFromSourceNormalized;
p = polyfit(x,y,1);
yfit = polyval(p,x);
% 	yfit = zeros(1,numel(y));
% 	maxt = max(OrderTime);
% 	mint = min(OrderTime);
% 	for myiter = 1:numel(y)
% 		t = OrderTime(myiter);
% 		yfit(myiter) = (t - mint) / (maxt - mint);
% 	end
%
yresid = y - yfit;
SSresid = sum(yresid.^2);
SStotal = (length(y)-1) * var(y);
rsq = 1 - SSresid/SStotal;
subplot(3,1,3);
scatter(OrderTime, OrderDistanceFromSourceNormalized, 100, '.');
set(gca,'FontSize',FontSizeAll)
hold on;
plot(OrderTime, yfit, 'r');
hold off;
title(['R^2=' num2str(rsq)],'FontSize',FontSizeAll)
xlabel('Time (msec)','FontSize',FontSizeAll)
ylabel('Geodesic Distance to Seeds','FontSize',FontSizeAll)
ylim([0 1])
dlmwrite([CurrentSaveDirectory 'GeodesicDistanceValue.dat'], rsq);

% 	x = OrderTime;
% 	y = OrderFlowDifferenceNormalized-OrderDistanceFromSourceNormalized;
% 	p = polyfit(x,y,1);
% 	yfit = polyval(p,x);
% 	yresid = y - yfit;
% 	SSresid = sum(yresid.^2);
% 	SStotal = (length(y)-1) * var(y);
% 	rsq = 1 - SSresid/SStotal;
% 	subplot(1,4,4);scatter(OrderTime, OrderFlowDifferenceNormalized-OrderDistanceFromSourceNormalized, 100, '.');
% 	set(gca,'FontSize',FontSizeAll)
% 	hold on;
% 	plot(OrderTime, yfit, 'r');
% 	hold off;
% 	title(['d. Flow Difference - Distance R^2=' num2str(rsq)],'FontSize',FontSizeAll)
% 	xlabel('time','FontSize',FontSizeAll)
% 	ylabel('Flow Difference - Distance','FontSize',FontSizeAll)
% 	ylim([-1 1])
set(gcf, 'Color', 'w');


if(savepdf)
    export_fig([CurrentSaveDirectory 'Metrics'], '-pdf', '-painters', '-a1', '-q101')
end

end