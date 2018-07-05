function rx = rotnx(phi)

phi = phi * pi/180;

c = cos(phi);
s = sin(phi);

rx = [1  0   0;
      0  c  -s;
      0  s   c];
end