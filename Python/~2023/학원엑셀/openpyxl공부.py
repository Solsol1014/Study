import openpyxl

wb=openpyxl.Workbook()
sheet=wb.active

sheet['B2']='B2'
sheet.cell(row=3, column=4).value='3, 4'
sheet.append([1, 2, 3, 4, 5])

wb.save("test.xlsx")