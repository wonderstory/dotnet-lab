using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
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

namespace iTunesCOM
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private iTunesLib.iTunesApp iTunes;
        public ObservableCollection<string> Tracks { get; } = new ObservableCollection<string>();

        public MainWindow()
        {
            InitializeComponent();

            Closing += MainWindow_Closing;

            iTunes = new iTunesLib.iTunesApp();
            iTunes.OnAboutToPromptUserToQuitEvent += ITunesApp_OnAboutToPromptUserToQuitEvent;
        }

        private void MainWindow_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            ReleaseComObject();
        }

        private void ITunesApp_OnAboutToPromptUserToQuitEvent()
        {
            ReleaseComObject();
            Application.Current.Shutdown();
        }

        public void ReleaseComObject()
        {
            if (iTunes == null) return;

            iTunes.OnAboutToPromptUserToQuitEvent -= ITunesApp_OnAboutToPromptUserToQuitEvent;

            Marshal.ReleaseComObject(iTunes);
            iTunes = null;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (iTunes == null) return;

            Tracks.Clear();

            foreach (iTunesLib.IITPlaylist playlist in iTunes.LibrarySource.Playlists)
            {
                Tracks.Add($"@ {playlist.Kind} {playlist.Name}");

                foreach (iTunesLib.IITTrack track in playlist.Tracks)
                {
                    if (track.Kind == iTunesLib.ITTrackKind.ITTrackKindFile
                        && track is iTunesLib.IITFileOrCDTrack f)
                    {
                        Tracks.Add($"{f.TrackDatabaseID} {f.KindAsString} {f.Name} {f.Artist} {f.Location}");
                    }
                }
            }

        }


        private IEnumerable<iTunesLib.IITTrack> GetAllTracks() => iTunes?.LibraryPlaylist.Tracks.OfType<iTunesLib.IITTrack>();

        private IEnumerable<iTunesLib.IITTrack> GetSelectedTracks()
        {
            var tracks = iTunes?.SelectedTracks;
            var count = tracks?.Count ?? 0;
            if (count <= 0) return null;

            var selectedTracks = new List<iTunesLib.IITTrack>(
                tracks.OfType<iTunesLib.IITTrack>());

            return selectedTracks;
        }
   }
}
