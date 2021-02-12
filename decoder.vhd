--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity decoder is

	port(
	
		wraddr: in std_logic_vector(1 downto 0);
		ld: in std_logic;
		y3,y2,y1,y0: out std_logic
	
	);
	
end entity;

architecture  df of decoder is

begin

	y3 <= wraddr(1) and wraddr(0) and ld;
	y2 <= wraddr(1) and not wraddr(0) and ld;
	y1 <= not wraddr(1) and wraddr(0) and ld;
	y0 <= not wraddr(1) and not wraddr(0) and ld;

end architecture;