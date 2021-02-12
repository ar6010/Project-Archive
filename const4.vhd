--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity const4 is

	port(
	
	y: out std_logic_vector(31 downto 0)
	
	);
	
end entity;

architecture df of const4 is 

begin 

y <= x"00000004";

end architecture;