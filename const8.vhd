--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity const8 is

	port(
	
	y: out std_logic_vector(31 downto 0)
	
	);
	
end entity;

architecture df of const8 is 

begin 

y <= x"00000008";

end architecture;