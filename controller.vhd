--Andrew Ramirez

library ieee;
use ieee.std_logic_1164.all;

entity controller is

	port(
	
		cond, rot: in std_logic_vector(3 downto 0);
		op: in std_logic_vector(1 downto 0);
		funct: in std_logic_vector(5 downto 0);
		mulIn: in std_logic_vector(3 downto 0);
		c, v, n, z: in std_logic;
		pcsrc, pcwr, regwr, alusrcb, cpsrwr, memrd, memwr, regsrc: out std_logic;
		mulS, mulS2: out std_logic;
		exts, regdst: out std_logic_vector(1 downto 0);
		alus: out std_logic_vector(2 downto 0);
		rotate: out std_logic_vector(3 downto 0)
	
	);
	
end entity;

architecture struct of controller is

begin

	pcsrc <= '0' when op = B"10" and cond = B"1110" else
				'0' when op = B"10" and  cond = B"0000" and z = '1' else
				'0' when op = B"10" and  cond = B"0001" and z = '0' else
				'1';
				
	pcwr <= '1';
	
	regdst <= "01" when op = "01" and funct(2) = '0' and funct(0) = '0' else
				 "10" when op = "00" and mulIn = "1001" and funct(5) = '0' else
				 "00";
				 
	mulS <= '1' when op = "00" and funct(5 downto 4) = "00" and mulIn = "1001" else
			  '0';
			  
	mulS2 <= '1' when op = "00" and funct(5 downto 4) = "00" and mulIn = "1001" else
			  '0';
				 
	regwr <= '0' when op = "00" and funct(4 downto 1) = "1010" else
				'1';
				
	exts <= "01" when op = "01" else
			  "10" when op = "10" else
			  "00";
			  
	rotate <= "0000";
	
	alusrcb <= '0' when funct(5) = '1' and op = "00" else
				  '0' when funct(5) = '0' and op = "01" else
				  '1';
				  
	alus <= "101" when op = "00" and funct(5 downto 4) = "00" and mulIn = "1001" else
				"001" when op = "00" and funct(4 downto 1) = "0010" else
			  "001" when op = "00" and funct(4 downto 1) = "1010" else
--			  "010" when op = "00" and funct(4 downto 1) = "0000" and mulIn(0) = '1' and funct(5) = '1' else
			  "010" when op = "00" and funct(4 downto 1) = "0000" and mulIn(0) = '0' else
			  "011" when op = "00" and funct(4 downto 1) = "1100" else
			  "100" when op = "00" and funct(4 downto 1) = "0001" else
			  "110" when op = "00" and funct(4 downto 1) = "1101" else
			  "000";
			  
	cpsrwr <= '1' when op = "00" and funct(4 downto 1) = "1010" else
				 '1' when op = "00" and funct(0) = '1' else
				 '0';
				 
	memrd <= '1' when op = "01" and funct(2) = '0' and funct(0) = '1' else
				'0';
				
	memwr <= '1' when op = "01" and funct(2) = '0' and funct(0) = '0' else
				'0';
				
	regsrc <= '0' when op = "01" and funct(2) = '0' and funct(0) = '1' else
				 '1';
	

end architecture;
	