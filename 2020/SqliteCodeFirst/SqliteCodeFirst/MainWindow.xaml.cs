using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SqliteCodeFirst
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public ObservableCollection<Record> Records { get; } = new ObservableCollection<Record>();

        public MainWindow()
        {
            InitializeComponent();

            Loaded += (s, e) =>
            {
                using var context = new RecordContext();
                //context.Database.EnsureDeleted();
                context.Database.EnsureCreated();
                if (!context.Records.Any())
                {
                    context.Add(new Record { Name = $"init_{DateTime.Now.Ticks}" });
                }
                context.Add(new Record { Name = $"aaa_{DateTime.Now.Ticks}" });
                context.SaveChanges();

                foreach (var r in context.Records)
                {
                    Records.Add(r);
                }
            };
        }
    }
}
