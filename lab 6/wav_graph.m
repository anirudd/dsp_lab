function [ a,b] = wav_graph( )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
f=fopen('data1.txt','r');
a=fscanf(f,'%c\n');
[~,c]=size(a);
b=zeros(1,c);
for i=1:c
    b(1,i)=str2num(a(1,i));
end


end

