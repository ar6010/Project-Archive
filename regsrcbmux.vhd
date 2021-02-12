--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity regsrcbmux is 

	port(
	
		d3, d2, d1,d0: in std_logic_vector(3 downto 0);
		s: in std_logic_vector(1 downto 0);
		y: out std_logic_vector(3 downto 0)
	
	);
	
end entity;

architecture df of regsrcbmux is

begin

	with s select y <=
		d3 when "11",
		d2 when "10",
		d1 when "01",
		d0 when others;

end architecture;