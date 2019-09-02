import csv
import pandas_datareader as pdr
from datetime import datetime

option = int(input("Select the Exchange: \n1.BSE\n2.NASDAQ\n"))
currentDT = datetime.now()
end_year = int(currentDT.year)
end_month = int(currentDT.month)
end_day = int(currentDT.day)

if(option == 1):
    scalar = 100
    stock = input("Select the stock: ")
    stock_file = pdr.get_data_yahoo(symbols = stock + '.ns', start = datetime(2010, 3, 30), end = datetime(end_year, end_month, end_day))
    indice_file = pdr.get_data_yahoo(symbols = "^BSESN", start = datetime(2010, 3, 30), end  = datetime(end_year, end_month, end_day))

elif(option == 2):
    scalar = 10
    stock = input("Select the stock: ")
    stock_file = pdr.get_data_yahoo(symbols = stock, start = datetime(2010, 3, 30), end = datetime(end_year, end_month, end_day))
    indice_file = pdr.get_data_yahoo(symbols = "^IXIC", start = datetime(2010, 3, 30), end  = datetime(end_year, end_month, end_day))
print("Extracted")

f_name = input("Enter the name of the file: ")
I_name = input("Enter the name of comaparator: ")
stock_close = stock_file['Close']
indice_close = indice_file['Close']/scalar
stock_close.to_csv(f_name + '.csv')
indice_close.to_csv(I_name + '.csv')
print("Saved")
