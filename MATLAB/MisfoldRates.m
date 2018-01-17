misfolddistance = 200;
ballmultiplier = 1000;
RoomSize = 10000;

numiter = 100;
SaveMatrix = zeros(100,100,numiter);
numtimesteps = 10;
for Cn = 0.01:0.01:1
	for Cm = 0.01:0.01:1
		if(Cn+Cm > 1)
			continue;
		end
		i = round(Cn*100);
		j = round(Cm*100);
		for iteration = 1:numiter
			%Number of balls
			ballsn = round(Cn*ballmultiplier);
			ballsm = round(Cm*ballmultiplier);
			%Balls coordinates
			Ncoordinates = randi(RoomSize,3,ballsn);
			Mcoordinates = randi(RoomSize,3,ballsm);
			
			for t = 1:numtimesteps
				while(1)
					%Apply misfolding
					if(isempty(Ncoordinates))
						break;
					end
					%3xballsn , 3xballsm -> NxM
					Distances = allDist(Ncoordinates, Mcoordinates);
					%Find balls which are close to each other
					[rows, cols] = find(Distances < misfolddistance);
					if(isempty(rows))
						break;
					end
					%every ball from n that had an M close will get misfolded
					rows = unique(rows);
					Mcoordinates = [Mcoordinates Ncoordinates(:,rows)];
					Ncoordinates = Ncoordinates(:,setdiff(1:size(Ncoordinates,2),rows));
				end
				%Apply movement
				if(isempty(Ncoordinates))
					break;
				end
				Ncoordinates = Ncoordinates + randi(2*RoomSize/100+1,3,size(Ncoordinates,2))-RoomSize/100;
				Mcoordinates = Mcoordinates + randi(2*RoomSize/100+1,3,size(Mcoordinates,2))-RoomSize/100;
			end
			ballsnend = size(Ncoordinates,2);
			ballsmend = size(Ncoordinates,2);
			SaveMatrix(i,j,iteration) = (ballsn-ballsnend)/ballmultiplier;
		end
		[i j]
	end
end
AvgMatrix = mean(SaveMatrix,3);

close all; imagesc(AvgMatrix);
OtherMatrix = zeros(100);
for Cn = 0.01:0.01:1
	for Cm = 0.01:0.01:1
		if(Cn+Cm > 1)
			break;
		end
		i = round(Cn*100);
		j = round(Cm*100);
		OtherMatrix(i,j) = Cn*Cm;
	end
end
figure;imagesc(OtherMatrix);
OtherMatrix = flipud(OtherMatrix);
AvgMatrix = flipud(AvgMatrix);


FontSizeAll = 16;
width = 25;
height = 10;
h2 = figure('visible','on','Units','centimeters', 'Position',[0 0 width height],...
		'PaperUnits','centimeters',...
		'PaperSize',[width height],...
		'PaperPositionMode','auto',...
		'InvertHardcopy', 'on',...
		'Renderer','painters'...
		);
set(gca,'FontSize',FontSizeAll)
set(gcf, 'Color', 'w');
subplot(1,2,1); imagesc([0.01 1], [0.01 1],AvgMatrix); xlabel('Cn','FontSize',FontSizeAll);ylabel('Cp','FontSize',FontSizeAll);	set(gcf, 'Color', 'w');colorbar; colormap hot;
set(gca,'FontSize',FontSizeAll)
set(gcf, 'Color', 'w');
subplot(1,2,2); imagesc([0.01 1], [0.01 1],OtherMatrix); xlabel('Cn','FontSize',FontSizeAll);ylabel('Cp','FontSize',FontSizeAll);	set(gcf, 'Color', 'w');colorbar; colormap hot;
set(gca,'FontSize',FontSizeAll)
set(gcf, 'Color', 'w');
export_fig('MisfoldModel', '-pdf', '-painters', '-a1', '-q101')

temp = AvgMatrix * 0.25 / max(max(AvgMatrix));
figure;imagesc(temp-OtherMatrix);