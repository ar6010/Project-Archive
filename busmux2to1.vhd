--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity busmux2to1 is

	port(
	
		d1,d0: in std_logic_vector(31 downto 0);
		s: in std_logic;
		y: out std_logic_vector(31 downto 0)
	
	);

end entity;

architecture df of busmux2to1 is

begin

	with s select y <=
	d1 when '1',
	d0 when others;

end architecture df;

