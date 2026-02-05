% ===============================
% pH Trend Analysis & Alert Logic
% ===============================

% --- Channel Details ---
phChannelID = 3227938;                  % WATER_01 Water pH
phReadKey   = 'D93G06OF65G309FU';

decisionChannelID = 3229185;            % Water_Quality_Decision
decisionWriteKey  = '3EQ91FU58HYFSQK8';

% --- Read last 4 pH values ---
phData = thingSpeakRead(phChannelID, ...
    'ReadKey', phReadKey, ...
    'Fields', 1, ...
    'NumPoints', 4);

% Remove NaN values
phData = phData(~isnan(phData));

% If no data, exit safely
if isempty(phData)
    disp('No pH data available');
    return;
end

% --- Basic Statistics ---
avgPH = mean(phData);
n = length(phData);
x = 1:n;

% Linear trend (slope)
p = polyfit(x, phData', 1);
slopePH = p(1);

% Predict next value
predictedPH = phData(end) + slopePH;

% --- Decision Logic ---
alertFlag = 0;
decisionCode = 0;

% SAFE: 6.5 – 8.5
if predictedPH < 6.0 || predictedPH > 9.0
    decisionCode = 3;   % pH Danger
    alertFlag = 1;
elseif (predictedPH >= 6.0 && predictedPH < 6.5) || ...
       (predictedPH > 8.5 && predictedPH <= 9.0)
    decisionCode = 1;   % pH Warning
else
    decisionCode = 0;   % Normal
end

% --- Write Decision Output ---
thingSpeakWrite(decisionChannelID, ...
    [alertFlag, decisionCode], ...
    'WriteKey', decisionWriteKey);
disp('pH analysis completed successfully');


%--------*----------*----------*-----------*---------*%


% Channel IDs
phChannelID = 3227938;
ecChannelID = 3227937;
decisionChannelID = 3229185;

% Read API Keys (leave empty if channels are public)
phReadKey = 'D93G06OF65G309FU';
ecReadKey = 'GLSO875NVRLQ2QRI';

% Read latest values
ph = thingSpeakRead(phChannelID, 'Fields', 1, 'NumPoints', 1, 'ReadKey', phReadKey);
ec = thingSpeakRead(ecChannelID, 'Fields', 1, 'NumPoints', 1, 'ReadKey', ecReadKey);

% Thresholds
phLow = 6.5;
phHigh = 8.5;
ecMax = 1500;

% Decision logic
alertFlag = 0;
if (ph < phLow) || (ph > phHigh) || (ec > ecMax)
    alertFlag = 1;
end

% Write to decision channel
thingSpeakWrite(decisionChannelID, ...
    [alertFlag, ph, ec], ...
    'Fields', [1, 2, 3]);
