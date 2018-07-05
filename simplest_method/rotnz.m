function rz = rotnz(psi)

psi = psi * pi/180;

c = cos(psi);
s = sin(psi);

rz = [c  -s   0;
      s   c   0;
      0   0   1];
end