clear all;
clc;
Data = load('XYZi.mat');
DataField = fieldnames(Data);
dlmwrite('XYZi.txt', (Data.(DataField{1}))');

Data = load('XYZj.mat');
DataField = fieldnames(Data');
dlmwrite('XYZj.txt', (Data.(DataField{1}))');